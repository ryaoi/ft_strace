#include "ft_strace.h"
#include "syscall64.h"
#include "syscall32.h"
#include <elf.h>
#include <sys/mman.h>

static void			get_fullpath(char *argname, char *exec_name)
{
	char			*path;
	char			*ptr;
	size_t			size;

	if (strchr(argname, '/') || (!(path = getenv("PATH"))))
	{
		strcpy(exec_name, argname);
		return ;
	}
	ptr = path;
	while ((ptr = strchr(path, ':')))
	{
		size = (size_t)ptr - (size_t)path;
		if (size + strlen(argname) >= PATH_MAX)
		{
			path = ptr + 1;
			continue ;
		}
		strncpy(exec_name, path, size);
		if (exec_name[size - 1] != '/')
		{
			exec_name[size] = '/';
			exec_name[size + 1] = '\0';
		}
		strcat(exec_name, argname);
		if (access(exec_name, X_OK) == 0)
			return ;
		path = ptr + 1;
	}
	memset(exec_name, 0, PATH_MAX);
}

static int					get_elfclass(char *binary_name)
{
	int						fd;
	struct stat				s;
	void					*map;
	size_t					size;
	Elf64_Ehdr				*header;
	int						ret;

	if (!(fd = open(binary_name, O_RDONLY)))
	{
		perror("open");
		return (0);
	}
	if ((fstat(fd, &s)) < 0)
	{
		perror("fstat");
		close(fd);
		return (0);
	}
	size = s.st_size;
	if (size < sizeof(Elf64_Ehdr))
	{
		close(fd);
		return (0);
	}
	if (!(map = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)))
	{
		perror("map");
		close(fd);
		return (0);
	}
	header = (Elf64_Ehdr *)map;

	ret  = header->e_ident[EI_CLASS];
	munmap(map, size);
	close(fd);
	return (ret);
}

static void					print_first_execve(pid_t child, int status, \
												const t_sys sys[], \
												sigset_t empty, \
												sigset_t mask)
{
	struct user_regs_struct regs;
	unsigned long long int	index_sys;
	char					*ret;

	if ((ptrace(PTRACE_SYSCALL, child, NULL, NULL)) < 0)
	{
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	if ((waitpid(child, &status, 0)) < 0)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
    handle_signal(child, status, sys64);
	ptrace(PTRACE_GETREGS, child, NULL, &regs);
    index_sys = regs.orig_rax;
	if (regs.orig_rax < (sizeof(sys64) / sizeof(sys64[0])))
    	(*(sys64[regs.orig_rax].handler))(child, regs, sys64[regs.orig_rax]);
	if ((ptrace(PTRACE_SYSCALL, child, NULL, NULL)) < 0)
	{
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	if ((sigprocmask(SIG_SETMASK, &empty, NULL)) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	if ((waitpid(child, &status, 0)) < 0)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	if ((sigprocmask(SIG_BLOCK, &mask, NULL)) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
    handle_signal(child, status, sys64);
	ptrace(PTRACE_GETREGS, child, NULL, &regs);
    if (regs.orig_rax < (sizeof(sys64) / sizeof(sys64[0])))
		ret = get_format(sys64[index_sys].ret, regs.rax, child);
	else
		ret = strdup("?");
	dprintf(2, " = %s\n", ret);
    if (ret)
    	free(ret);
    if (sys == sys32)
    {
		dprintf(2, "strace: [ Process PID=%d runs in 32 bit mode. ]\n", getpid());
    }
}

static void					init_sigset(sigset_t *empty, sigset_t *mask)
{
	if ((sigemptyset(empty)) < 0 || (sigemptyset(mask)) < 0)
	{
		perror("sigemtypset");
		exit(EXIT_FAILURE);
	}
	if (((sigaddset(mask, SIGHUP)) < 0) \
		|| ((sigaddset(mask, SIGQUIT)) < 0) \
		|| ((sigaddset(mask, SIGINT)) < 0) \
		|| ((sigaddset(mask, SIGPIPE)) < 0) \
		|| ((sigaddset(mask, SIGTERM)) < 0))
	{
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}
}

static int					call_syscall(pid_t child, sigset_t *empty, \
										sigset_t *mask, int status, const t_sys sys[])
{
    if ((ptrace(PTRACE_SYSCALL, child, NULL, NULL)) < 0)
    {
		perror("ptrace");
		exit(EXIT_FAILURE);
    }
	if ((sigprocmask(SIG_SETMASK, empty, NULL)) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
    if ((waitpid(child, &status, 0)) < 0)
    {
		perror("waitpid");
		exit(EXIT_FAILURE);
    }
	if ((sigprocmask(SIG_BLOCK, mask, NULL)) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
   	if ((handle_signal(child, status, sys)))
    	return (1);
    return (0);
}

static void					trace_process(char *argv[], \
											char *envp[], char *binary_name, \
											const t_sys sys[])
{
	pid_t					child;
	int						status;
	struct user_regs_struct regs;
    char					*ret;
	unsigned long long int	index_sys;
	int						printed;
	sigset_t				empty;
	sigset_t				mask;

	child = fork();
	if (child < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		 if ((execve(binary_name, argv + 1, envp)) < 0)
		 {
		 	perror("execve");
		 	exit(EXIT_FAILURE);
		 }
	}
	else {
		init_sigset(&empty, &mask);
		ptrace(PTRACE_SEIZE, child, NULL, 0);
		ptrace(PTRACE_INTERRUPT, child, NULL, NULL);
		ptrace(PTRACE_SETOPTIONS, child, NULL, PTRACE_O_TRACESYSGOOD);
		wait(&status);
		print_first_execve(child, status, sys, empty, mask);
		while (1)
		{
			if ((call_syscall(child, &empty, &mask, status, sys)))
           		continue ;
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
            index_sys = regs.orig_rax;
            if (sys == sys64)
            {
            	if ((regs.orig_rax >= (sizeof(sys64) / sizeof(sys[0]))) || sys[index_sys].name == NULL)
            		continue;
            }
            else
            {
            	if ((regs.orig_rax >= (sizeof(sys32) / sizeof(sys[0]))) || sys[index_sys].name == NULL)
            		continue;
            }
            if (strcmp(sys[index_sys].name, "read") == 0 \
            	|| strcmp(sys[index_sys].name, "getdents") == 0) //read or getdents
            {
            	if ((call_syscall(child, &empty, &mask, status, sys)))
            		continue ;
			    ptrace(PTRACE_GETREGS, child, NULL, &regs);
                printed = (*(sys[regs.orig_rax].handler))(child, regs, sys[regs.orig_rax]);
            }
            else
            {
                printed = (*(sys[regs.orig_rax].handler))(child, regs, sys[regs.orig_rax]);
            	if ((call_syscall(child, &empty, &mask, status, sys)))
            		continue ;
			    ptrace(PTRACE_GETREGS, child, NULL, &regs);
            }
            if ((long long int)regs.rax >= 0 || strcmp(sys[index_sys].name, "exit_group") == 0)
				ret = get_format(sys[index_sys].ret, regs.rax, child);
			else
				ret = get_error(regs.rax);
            if (printed > 40)
                dprintf(2, " = %s\n", ret);
            else
                dprintf(2, "%*c = %s\n", 40 - printed, ' ', ret);
            if (ret)
            	free(ret);
		}
	}

}

int main(int argc, char *argv[], char *envp[])
{
	char		exec_name[PATH_MAX + 1] = {0};
	int			type;
	const t_sys		*sys;

	if (argc < 2)
	{
		dprintf(2, "Usage: ./ft_strace PROG [ARGS]\n");
		return (0);
	}
	if (strlen(argv[1]) >= PATH_MAX)
	{
		dprintf(2, "ft_strace: exec: File name too long\n");
		return (0);
	}
	get_fullpath(argv[1], exec_name);
	if (!(strlen(exec_name)))
	{
		dprintf(2, "ft_strace: can't stat: '%s': %s\n", argv[1], strerror(errno));
		return (0);
	}
	if (!(type = get_elfclass(exec_name)))
	{
		dprintf(2, "ft_strace: exec: file is corrupted\n");
		return (0);
	}
	if (type == 1)
		sys = sys32;
	else if (type == 2)
		sys = sys64;
	trace_process(argv, envp, exec_name, sys);
	return (0);
}
