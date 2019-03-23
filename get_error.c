#include "ft_strace.h"
#include <errno.h>

#define ERESTARTSYS 512
#define ERESTARTNOINTR	513
#define ERESTARTNOHAND	514	/* restart if no handler.. */
#define ENOIOCTLCMD	515	/* No ioctl command */
#define ERESTART_RESTARTBLOCK 516 /* restart by calling sys_restart_syscall */
#define EPROBE_DEFER	517	/* Driver requests probe retry */
#define EOPENSTALE	518	/* open found a stale dentry */
#define ENOPARAM	519	/* Parameter not supported */

const char *error2name(int errnum)
{
		switch (errnum) {
				CASE(EPERM);
				CASE(ENOENT);
				CASE(ESRCH);
				CASE(EINTR);
				CASE(EIO);
				CASE(ENXIO);
				CASE(E2BIG);
				CASE(ENOEXEC);
				CASE(EBADF);
				CASE(ECHILD);
				CASE(EAGAIN);
				CASE(ENOMEM);
				CASE(EACCES);
				CASE(EFAULT);
				CASE(ENOTBLK);
				CASE(EBUSY);
				CASE(EEXIST);
				CASE(EXDEV);
				CASE(ENODEV);
				CASE(ENOTDIR);
				CASE(EISDIR);
				CASE(EINVAL);
				CASE(ENFILE);
				CASE(EMFILE);
				CASE(ENOTTY);
				CASE(ETXTBSY);
				CASE(EFBIG);
				CASE(ENOSPC);
				CASE(ESPIPE);
				CASE(EROFS);
				CASE(EMLINK);
				CASE(EPIPE);
				CASE(EDOM);
				CASE(ERANGE);
				CASE(EDEADLK);
				CASE(ENAMETOOLONG);
				CASE(ENOLCK);
				CASE(ENOSYS);
				CASE(ENOTEMPTY);
				CASE(ELOOP);
				CASE(ENOMSG);
				CASE(EIDRM);
				CASE(ECHRNG);
				CASE(EL2NSYNC);
				CASE(EL3HLT);
				CASE(EL3RST);
				CASE(ELNRNG);
				CASE(EUNATCH);
				CASE(ENOCSI);
				CASE(EL2HLT);
				CASE(EBADE);
				CASE(EBADR);
				CASE(EXFULL);
				CASE(ENOANO);
				CASE(EBADRQC);
				CASE(EBADSLT);
				CASE(EBFONT);
				CASE(ENOSTR);
				CASE(ENODATA);
				CASE(ETIME);
				CASE(ENOSR);
				CASE(ENONET);
				CASE(ENOPKG);
				CASE(EREMOTE);
				CASE(ENOLINK);
				CASE(EADV);
				CASE(ESRMNT);
				CASE(ECOMM);
				CASE(EPROTO);
				CASE(EMULTIHOP);
				CASE(EDOTDOT);
				CASE(EBADMSG);
				CASE(EOVERFLOW);
				CASE(ENOTUNIQ);
				CASE(EBADFD);
				CASE(EREMCHG);
				CASE(ELIBACC);
				CASE(ELIBBAD);
				CASE(ELIBSCN);
				CASE(ELIBMAX);
				CASE(ELIBEXEC);
				CASE(EILSEQ);
				CASE(ERESTART);
				CASE(ESTRPIPE);
				CASE(EUSERS);
				CASE(ENOTSOCK);
				CASE(EDESTADDRREQ);
				CASE(EMSGSIZE);
				CASE(EPROTOTYPE);
				CASE(ENOPROTOOPT);
				CASE(EPROTONOSUPPORT);
				CASE(ESOCKTNOSUPPORT);
				CASE(EOPNOTSUPP);
				CASE(EPFNOSUPPORT);
				CASE(EAFNOSUPPORT);
				CASE(EADDRINUSE);
				CASE(EADDRNOTAVAIL);
				CASE(ENETDOWN);
				CASE(ENETUNREACH);
				CASE(ENETRESET);
				CASE(ECONNABORTED);
				CASE(ECONNRESET);
				CASE(ENOBUFS);
				CASE(EISCONN);
				CASE(ENOTCONN);
				CASE(ESHUTDOWN);
				CASE(ETOOMANYREFS);
				CASE(ETIMEDOUT);
				CASE(ECONNREFUSED);
				CASE(EHOSTDOWN);
				CASE(EHOSTUNREACH);
				CASE(EALREADY);
				CASE(EINPROGRESS);
				CASE(ESTALE);
				CASE(EUCLEAN);
				CASE(ENOTNAM);
				CASE(ENAVAIL);
				CASE(EISNAM);
				CASE(EREMOTEIO);
				CASE(EDQUOT);
				CASE(ENOMEDIUM);
				CASE(EMEDIUMTYPE);
				CASE(ERESTARTSYS);
				CASE(ERESTARTNOINTR);
				CASE(ERESTARTNOHAND);
				CASE(ENOIOCTLCMD);
				CASE(ERESTART_RESTARTBLOCK);
				CASE(EPROBE_DEFER);
				CASE(EOPENSTALE);
				CASE(ENOPARAM);
				default:
				return ("Undefined error");
		}
}

const char *error2description(int errnum)
{
		switch(errnum) {
				case(EPERM): return("Operation not permitted");
				case(ENOENT): return("No such file or directory");
				case(ESRCH): return("No such process");
				case(EINTR): return("Interrupted system call");
				case(EIO): return("I/O error");
				case(ENXIO): return("No such device or address");
				case(E2BIG): return("Arg list too long");
				case(ENOEXEC): return("Exec format error");
				case(EBADF): return("Bad file descriptor");
				case(ECHILD): return("No child processes");
				case(EAGAIN): return("Try again");
				case(ENOMEM): return("Out of memory");
				case(EACCES): return("Permission denied");
				case(EFAULT): return("Bad address");
				case(ENOTBLK): return("Block device required");
				case(EBUSY): return("Device or resource busy");
				case(EEXIST): return("File exists");
				case(EXDEV): return("Cross-device link");
				case(ENODEV): return("No such device");
				case(ENOTDIR): return("Not a directory");
				case(EISDIR): return("Is a directory");
				case(EINVAL): return("Invalid argument");
				case(ENFILE): return("File table overflow");
				case(EMFILE): return("Too many open files");
				case(ENOTTY): return("Not a typewriter");
				case(ETXTBSY): return("Text file busy");
				case(EFBIG): return("File too large");
				case(ENOSPC): return("No space left on device");
				case(ESPIPE): return("Illegal seek");
				case(EROFS): return("Read-only file system");
				case(EMLINK): return("Too many links");
				case(EPIPE): return("Broken pipe");
				case(EDOM): return("Math argument out of domain of func");
				case(ERANGE): return("Math result not representable");
				case(EDEADLK): return("Resource deadlock would occur");
				case(ENAMETOOLONG): return("File name too long");
				case(ENOLCK): return("No record locks available");
				case(ENOSYS): return("Function not implemented");
				case(ENOTEMPTY): return("Directory not empty");
				case(ELOOP): return("Too many symbolic links encountered");
				case(ENOMSG): return("No message of desired type");
				case(EIDRM): return("Identifier removed");
				case(ECHRNG): return("Channel number out of range");
				case(EL2NSYNC): return("Level 2 not synchronized");
				case(EL3HLT): return("Level 3 halted");
				case(EL3RST): return("Level 3 reset");
				case(ELNRNG): return("Link number out of range");
				case(EUNATCH): return("Protocol driver not attached");
				case(ENOCSI): return("No CSI structure available");
				case(EL2HLT): return("Level 2 halted");
				case(EBADE): return("Invalid exchange");
				case(EBADR): return("Invalid request descriptor");
				case(EXFULL): return("Exchange full");
				case(ENOANO): return("No anode");
				case(EBADRQC): return("Invalid request code");
				case(EBADSLT): return("Invalid slot");
				case(EBFONT): return("Bad font file format");
				case(ENOSTR): return("Device not a stream");
				case(ENODATA): return("No data available");
				case(ETIME): return("Timer expired");
				case(ENOSR): return("Out of streams resources");
				case(ENONET): return("Machine is not on the network");
				case(ENOPKG): return("Package not installed");
				case(EREMOTE): return("Object is remote");
				case(ENOLINK): return("Link has been severed");
				case(EADV): return("Advertise error");
				case(ESRMNT): return("Srmount error");
				case(ECOMM): return("Communication error on send");
				case(EPROTO): return("Protocol error");
				case(EMULTIHOP): return("Multihop attempted");
				case(EDOTDOT): return("RFS specific error");
				case(EBADMSG): return("Not a data message");
				case(EOVERFLOW): return("Value too large for defined data type");
				case(ENOTUNIQ): return("Name not unique on network");
				case(EBADFD): return("File descriptor in bad state");
				case(EREMCHG): return("Remote address changed");
				case(ELIBACC): return("Can not access a needed shared library");
				case(ELIBBAD): return("Accessing a corrupted shared library");
				case(ELIBMAX): return("Attempting to link in too many shared libraries");
				case(ELIBEXEC): return("Cannot exec a shared library directly");
				case(EILSEQ): return("Illegal byte sequence");
				case(ERESTART): return("Interrupted system call should be restarted");
				case(ESTRPIPE): return("Streams pipe error");
				case(EUSERS): return("Too many users");
				case(ENOTSOCK): return("Socket operation on non-socket");
				case(EDESTADDRREQ): return("Destination address required");
				case(EMSGSIZE): return("Message too long");
				case(EPROTOTYPE): return("Protocol wrong type for socket");
				case(ENOPROTOOPT): return("Protocol not available");
				case(EPROTONOSUPPORT): return("Protocol not supported");
				case(ESOCKTNOSUPPORT): return("Socket type not supported");
				case(EOPNOTSUPP): return("Operation not supported on transport endpoint");
				case(EPFNOSUPPORT): return("Protocol family not supported");
				case(EAFNOSUPPORT): return("Address family not supported by protocol");
				case(EADDRINUSE): return("Address already in use");
				case(EADDRNOTAVAIL): return("Cannot assign requested address");
				case(ENETDOWN): return("Network is down");
				case(ENETUNREACH): return("Network is unreachable");
				case(ENETRESET): return("Network dropped connection because of reset");
				case(ECONNABORTED): return("Software caused connection abort");
				case(ECONNRESET): return("Connection reset by peer");
				case(ENOBUFS): return("No buffer space available");
				case(EISCONN): return("Transport endpoint is already connected");
				case(ENOTCONN): return("Transport endpoint is not connected");
				case(ESHUTDOWN): return("Cannot send after transport endpoint shutdown");
				case(ETIMEDOUT): return("Connection timed out");
				case(ECONNREFUSED): return("Connection refused");
				case(EHOSTDOWN): return("Host is down");
				case(EHOSTUNREACH): return("No route to host");
				case(EALREADY): return("Operation already in progress");
				case(EINPROGRESS): return("Operation now in progress");
				case(ESTALE): return("Stale NFS file handle");
				case(EUCLEAN): return("Structure needs cleaning");
				case(ENOTNAM): return("Not a XENIX named type file");
				case(ENAVAIL): return("No XENIX semaphores available");
				case(EISNAM): return("Is a named type file");
				case(EREMOTEIO): return("Remote I/O error");
				case(EDQUOT): return("Quota exceeded");
				case(ENOMEDIUM): return("No medium found");
				case(EMEDIUMTYPE): return("Wrong medium type");
				case(ERESTARTSYS): return("To be restarted if SA_RESTART is set");
				case(ERESTARTNOINTR): return("To be restarted if SA_RESTART is set");
				case(ERESTARTNOHAND): return("restart if no handler..");
				case(ENOIOCTLCMD): return("No ioctl command");
				case(ERESTART_RESTARTBLOCK): return("restart by calling sys_restart_syscall");
				case(EPROBE_DEFER): return("Driver requests probe retry");
				case(EOPENSTALE): return("open found a stale dentry");
				case(ENOPARAM): return("Parameter not supported");
				default:
								   return ("undefined description");
		}
}

char		*get_error(unsigned long long int reg)
{
		char	*ret;

		if ((unsigned short)reg >= ERESTARTSYS && (unsigned int)reg <= ENOPARAM)
		{
			if (!(asprintf(&ret, "? %s (%s)", error2name(ERESTARTSYS), error2description(ERESTARTSYS))))
				return (NULL);
			return (ret);
		}
		if (-reg == ERESTARTSYS)
		{
			if (!(asprintf(&ret, "? %s (%s)", error2name(-reg), error2description(-reg))))
				return (NULL);
			return (ret);
		}
		if (!(asprintf(&ret, "%d %s (%s)", -1, error2name(-reg), error2description(-reg))))
			return (NULL);
		return (ret);
}
