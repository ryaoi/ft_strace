#ifndef FT_STRACE_H
# define FT_STRACE_H

# define _GNU_SOURCE
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ptrace.h>
# include <sys/user.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <errno.h>

# define UNDEF 0
# define ULONG 1
# define LONG 2
# define UINT 3
# define INT 4
# define SIZE_T 5
# define SSIZE_T 6
# define PTR 7
# define STR 8
# define STRUCT 9
# define VOID 10
# define HEX 11
# define PROT 12
# define FLAGS 13
# define MAP 14

#define CASE(x) case x: return #x

typedef struct s_sys {
	char *name;
	int nargs;
	int typearg[6];
	int ret;
    int    (*handler)(pid_t, struct user_regs_struct, struct s_sys);
}               t_sys;

int				handle_signal(pid_t pid, int status, const t_sys sys[]);
int             handle_read(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_read32(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_write(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_write32(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_execve(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_execve32(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_openat(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_openat32(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_getdents(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_getdents32(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_default(pid_t pid, struct user_regs_struct regs, t_sys sys);
int             handle_default32(pid_t pid, struct user_regs_struct regs, t_sys sys);
char            *get_string(pid_t pid, unsigned long addr);
char            *get_chars(pid_t pid, unsigned long addr, int rax);
char            *get_format(int type, unsigned long long int reg, pid_t pid);
char            *get_flags(unsigned long param);
char            *get_map(unsigned long param);
char            *get_entries(pid_t pid, unsigned long addr, unsigned int count, int rax);
char            *get_vars(pid_t pid, unsigned long addr);
char            *get_args(pid_t pid, unsigned long addr);
char            *get_prot(unsigned long addr);
char            *get_error(unsigned long long int reg);

#endif
