
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

int			handle_signal(pid_t child, int status, const t_sys sys[])
{
	siginfo_t	sig;
	struct user_regs_struct regs;

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
				return (1);
			}
			else if (sig.si_signo == SIGINT || sig.si_signo == SIGTSTP || sig.si_signo == SIGCONT)
			//else if (sig.si_signo == SIGTSTP || sig.si_signo == SIGCONT)
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code));
				(void)regs;
				return (1);
			}
			else
			{
				dprintf(2, "--- %s {si_signo=%s, si_code=%s, si_pid=%d, si_uid=%d} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code), \
						sig.si_pid, sig.si_uid);
				dprintf(2, "+++ killed by %s +++\n", signal2name(WSTOPSIG(status)));
				exit(0);
			}
//			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
//			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			(void)sys;
//			printf("relaunch syscall :%hd!\n", (short)regs.orig_rax);
//			int printed = (*(sys[(int)regs.orig_rax].handler))(child, regs, sys[(int)regs.orig_rax]);
//			printf("printed:%d\n", printed);
		}
//		return (1);
	}
	return (0);
}
