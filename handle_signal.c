
#include "ft_strace.h"
#include <signal.h>

#define SIGSTKFLT 16
//#define SIGIO 29
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
	// CASE(SIGKILL); // can not be caught
	CASE(SIGUSR1);
	CASE(SIGSEGV);
	CASE(SIGUSR2);
	CASE(SIGPIPE);
	CASE(SIGALRM);
	CASE(SIGTERM);
	CASE(SIGSTKFLT); 
	CASE(SIGCHLD);
	CASE(SIGCONT);
	// CASE(SIGSTOP); // can not be caught
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


void			handle_signal(pid_t child, int status)
{
	siginfo_t	sig;
	if (WIFSTOPPED(status))
	{
		ptrace(PTRACE_GETSIGINFO, child, NULL, &sig);
		if (sig.si_signo != SIGTRAP)
		{
			if (sig.si_signo == SIGCHLD)
				printf("--- %s {si_signo=%s, si_code=%s, si_pid=%d, si_uid=%d, si_status=%d, si_utime=%ld, si_stime=%ld} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), childcode2name(sig.si_code), \
						sig.si_pid, sig.si_uid, sig.si_status, sig.si_utime, sig.si_stime);
			else if (sig.si_signo == SIGTTIN)
				printf("--- %s {si_signo=%s, si_code=%s, si_pid=%d, si_uid=%d} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code), \
						sig.si_pid, sig.si_uid);
			else
				printf("--- %s {si_signo=%s, si_code=%s} ---\n", \
						signal2name(sig.si_signo), signal2name(sig.si_signo), code2name(sig.si_code));
		}

	}
}
