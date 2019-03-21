
#include "ft_strace.h"
#include <signal.h>

#define SIGSTKFLT 16
#define SIGPWR 30

const char * signal2name(int sig)
{
	switch (sig) {
	CASE(SIGHUP);
	CASE(SIGINT);
	CASE(SIGQUIT);
	CASE(SIGILL);
	CASE(SIGTRAP);
	CASE(SIGABRT);
	CASE(SIGBUS);
	CASE(SIGFPE);
	CASE(SIGKILL); // can not be caught
	CASE(SIGUSR1);
	CASE(SIGSEGV);
	CASE(SIGUSR2);
	CASE(SIGPIPE);
	CASE(SIGALRM);
	CASE(SIGTERM);
	CASE(SIGSTKFLT); 
	CASE(SIGCHLD);
	CASE(SIGCONT);
	CASE(SIGSTOP); // can not be caught
	CASE(SIGTSTP);
	CASE(SIGTTIN);
	CASE(SIGTTOU);
	CASE(SIGURG);
	CASE(SIGXCPU);
	CASE(SIGXFSZ);
	CASE(SIGVTALRM);
	CASE(SIGPROF);
	CASE(SIGWINCH);
	CASE(SIGIO);
	CASE(SIGPWR);
	CASE(SIGSYS);
	default:
		return ("Undefined signal");
	}
}

const char *childcode2name(int code)
{
	switch (code){
	CASE(CLD_EXITED);
	CASE(CLD_KILLED);
	CASE(CLD_DUMPED);
	CASE(CLD_TRAPPED);
	CASE(CLD_STOPPED);
	CASE(CLD_CONTINUED);
	default:
		return ("Undefined code");
	}
}

const char *code2name(int code)
{
	switch (code){
	CASE(SI_USER);
	CASE(SI_KERNEL);
	CASE(SI_QUEUE);
	CASE(SI_TIMER);
	CASE(SI_MESGQ);
	CASE(SI_ASYNCIO);
	CASE(SI_SIGIO);
	CASE(SI_TKILL);
	default:
		return ("Undefined code");
	}
}

/*
#define SEGV_MAPERR	1	
#define SEGV_ACCERR	2	
#define SEGV_BNDERR	3
#ifdef __ia64__
# define __SEGV_PSTKOVF	4	
#else
# define SEGV_PKUERR	4	
#endif
#define SEGV_ACCADI	5	
#define SEGV_ADIDERR	6	
#define SEGV_ADIPERR	7	
#define NSIGSEGV	7
*/

const char *segvcode2name(int code)
{
	switch (code){
	CASE(SEGV_MAPERR);
	CASE(SEGV_ACCERR);
	CASE(SEGV_BNDERR);
	CASE(SEGV_PKUERR);
	//CASE(SEGV_ACCADI);
	//CASE(SEGV_ADIDERR);
	//CASE(SEGV_ADIPERR);
	//CASE(NSIGSEGV);
	default:
		return ("Undefined code");
	}
}

static void	print_syscall_sig(pid_t child, int status, const t_sys sys[], \
							siginfo_t sig)
{
	int printed;
	char *ret;
	unsigned long long int sys_index;
	struct user_regs_struct regs;

	ptrace(PTRACE_SYSCALL, child, NULL, sig.si_signo);
	waitpid(child, &status, 0);
	ptrace(PTRACE_GETREGS, child, NULL, &regs);
	sys_index = regs.orig_rax;
	printed = (*(sys[regs.orig_rax].handler))(child, regs, sys[regs.orig_rax]);
	ptrace(PTRACE_SYSCALL, child, NULL, sig.si_signo);
	waitpid(child, &status, 0);
	ptrace(PTRACE_GETREGS, child, NULL, &regs);
	if ((long long int)regs.rax >= 0)
		ret = get_format(sys[sys_index].ret, regs.rax, child);
	else
		ret = get_error(regs.rax);
	if (printed > 40)
		dprintf(2, " = %s\n", ret);
	else
		dprintf(2, "%*c = %s\n", 40 - printed, ' ', ret);
	if (ret)
		free(ret);
	ptrace(PTRACE_SYSCALL, child, NULL, sig.si_signo);
	waitpid(child, &status, 0);
}

int			handle_signal(pid_t child, int status, const t_sys sys[])
{
	siginfo_t	sig;

	if (WIFEXITED(status))
	{
		printf("%*c= ?\n", 28, ' ');
		printf("+++ exited with %d +++\n", WEXITSTATUS(status));
		exit(0);
	}
	else if (WIFSIGNALED(status))
	{
		printf("+++ killed by %s +++\n", signal2name(WTERMSIG(status)));
		exit(0);
	}
	if ((WIFSTOPPED(status)))
	{
		ptrace(PTRACE_GETSIGINFO, child, NULL, &sig);
		if (sig.si_signo != SIGTRAP)
		{
			if (sig.si_signo == SIGCHLD)
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s, si_pid=%d, si_uid=%d, si_status=%d, si_utime=%ld, si_stime=%ld} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), childcode2name(sig.si_code), \
						sig.si_pid, sig.si_uid, sig.si_status, sig.si_utime, sig.si_stime);
				//print_syscall_sig(child, status, sys, sig);
				return (1);
			}
			else if (sig.si_signo == SIGSEGV)
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s, si_addr=%p} ---\n", \
					signal2name(sig.si_signo), signal2name(sig.si_signo), segvcode2name(sig.si_code), \
					sig.si_addr);
				dprintf(2, "+++ killed by %s +++\nSegmentation fault\n", signal2name(WSTOPSIG(status)));
				exit(sig.si_status);
			}
			else if (sig.si_signo == SIGINT || sig.si_signo == SIGTSTP \
						|| sig.si_signo == SIGCONT)
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code));
				if (sig.si_signo == SIGINT)
					print_syscall_sig(child, status, sys, sig);
				return (1);
			}
			else
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s, si_pid=%d, si_uid=%d} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code), \
						sig.si_pid, sig.si_uid);
				if (sig.si_signo == SIGWINCH)
				{
					print_syscall_sig(child, status, sys, sig);
					return (1);
				}
				dprintf(2, "+++ killed by %s +++\n", signal2name(WSTOPSIG(status)));
				exit(sig.si_status);
			}
		}
	}
	return (0);
}
