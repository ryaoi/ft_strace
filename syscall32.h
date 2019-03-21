#ifndef __SYSTABLE32_H__
# define __SYSTABLE32_H__

/* /usr/include/asm/unistd_32.h */

# include "ft_strace.h"

const t_sys sys32[] = {
	[0] = {"restart_syscall", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[1] = {"exit", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[2] = {"fork", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[3] = {"read", 3, {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_read32 },
	[4] = {"write", 3, {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_write32 },
	[5] = {"open", 2, {STR, FLAGS, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[6] = {"close", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[7] = {"waitpid", 4, {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[8] = {"creat", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[9] = {"link", 2, {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[10] = {"unlink", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[11] = {"execve", 3, {STR, STR, STR, UNDEF, UNDEF, UNDEF}, INT, handle_execve },
	[12] = {"chdir", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[13] = {"time", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[14] = {"mknod", 3, {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[15] = {"chmod", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[16] = {"lchown", 3, {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[19] = {"lseek", 3, {INT, LONG, INT, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[20] = {"getpid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[21] = {"mount", 5, {STR, STR, STR, ULONG, PTR, UNDEF}, INT, handle_default32 },
	[23] = {"setuid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[24] = {"getuid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[26] = {"ptrace", 4, {LONG, INT, PTR, PTR, UNDEF, UNDEF}, LONG, handle_default32 },
	[27] = {"alarm", 1, {UINT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, UINT, handle_default32 },
	[29] = {"pause", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[30] = {"utime", 2, {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[33] = {"access", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[36] = {"sync", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[37] = {"kill", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[38] = {"rename", 2, {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[39] = {"mkdir", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[40] = {"rmdir", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[41] = {"dup", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[42] = {"pipe", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[43] = {"times", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[44] = {"prof", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[45] = {"brk", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR, handle_default32 },
	[46] = {"setgid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[47] = {"getgid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[48] = {"signal", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[49] = {"geteuid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[50] = {"getegid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[51] = {"acct", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[52] = {"umount2", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[53] = {"lock", 0, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[54] = {"ioctl", 3, {INT, ULONG, STRUCT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[55] = {"fcntl", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[56] = {"mpx", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[57] = {"setpgid", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[58] = {"ulimit", 2, {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[59] = {"oldolduname", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[60] = {"umask", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[61] = {"chroot", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[62] = {"ustat", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[63] = {"dup2", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[64] = {"getppid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[65] = {"getpgrp", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[66] = {"setsid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[67] = {"sigaction", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[68] = {"sgetmask", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[69] = {"ssetmask", 1, {LONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[70] = {"setreuid", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[71] = {"setregid", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[72] = {"sigsuspend", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[73] = {"sigpending", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[74] = {"sethostname", 2, {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[75] = {"setrlimit", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[76] = {"getrlimit", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[77] = {"getrusage", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[78] = {"gettimeofday", 2, {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[79] = {"settimeofday", 2, {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[80] = {"getgroups", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[81] = {"setgroups", 2, {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[82] = {"select", 5, {INT, PTR, PTR, PTR, PTR, UNDEF}, INT, handle_default32 },
	[83] = {"symlink", 2, {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[84] = {"oldlstat", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[85] = {"readlink", 3, {STR, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[86] = {"uselib", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[87] = {"swapon", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[88] = {"reboot", 4, {INT, INT, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[89] = {"readdir", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR, handle_default32 },
	[90] = {"mmap", 6, {PTR, SIZE_T, PROT, MAP, INT, HEX} , PTR, handle_default32 },
	[91] = {"munmap", 2, {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[92] = {"truncate", 2, {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[93] = {"ftruncate", 2, {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[94] = {"fchmod", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[95] = {"fchown", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[96] = {"getpriority", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[97] = {"setpriority", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[99] = {"statfs", 2, {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[100] = {"fstatfs", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[101] = {"ioperm", 3, {ULONG, ULONG, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[102] = {"socketcall", 2, {INT, ULONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[103] = {"syslog", 2, {INT, STR, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[104] = {"setitimer", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[105] = {"getitimer", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[106] = {"stat", 2, {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[107] = {"lstat", 2, {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[108] = {"fstat", 2, {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[109] = {"olduname", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[110] = {"iopl", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[111] = {"vhangup", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[112] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[113] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[114] = {"wait4", 4, {INT, PTR, INT, PTR, UNDEF, UNDEF} , INT, handle_default32 },
	[115] = {"swapoff", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[116] = {"sysinfo", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[117] = {"ipc", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[118] = {"fsync", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[119] = {"sigreturn", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[120] = {"clone", 4, {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[121] = {"setdomainname", 2, {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[122] = {"uname", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[123] = {"modify_ldt", 3, {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[124] = {"adjtimex", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[125] = {"mprotect", 3, {PTR, SIZE_T, PROT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[127] = {"create_module", 1, {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR, handle_default32 },
	[128] = {"init_module", 3, {PTR, ULONG, STR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[129] = {"delete_module", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[130] = {"get_kernel_syms", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[131] = {"quotactl", 4, {INT, STR, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[132] = {"getpgid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[133] = {"fchdir", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[134] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[135] = {"sysfs", 3, {INT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[136] = {"personality", 1, {ULONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[137] = {"afs_syscall", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[138] = {"setfsuid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[139] = {"setfsgid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[140] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[141] = {"getdents", 3, {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF} , INT, handle_getdents32 },
	[142] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[143] = {"flock", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[144] = {"msync", 3, {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[145] = {"readv", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[146] = {"writev", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF} , SSIZE_T, handle_default32 },
	[147] = {"getsid", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[148] = {"fdatasync", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[149] = {"_sysctl", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[150] = {"mlock", 2, {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[151] = {"munlock", 2, {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[152] = {"mlockall", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[153] = {"munlockall", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[154] = {"sched_setparam", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[155] = {"sched_getparam", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[156] = {"sched_setscheduler", 3, {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[157] = {"sched_getscheduler", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[158] = {"sched_yield", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[159] = {"sched_get_priority_max", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[160] = {"sched_get_priority_min", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[161] = {"sched_rr_get_interval", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[162] = {"nanosleep", 2, {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[163] = {"mremap", 5, {PTR, SIZE_T, SIZE_T, INT, PTR, UNDEF}, PTR, handle_default32 },
	[164] = {"setresuid", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[165] = {"getresuid", 3, {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[166] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[167] = {"query_module", 5, {STR, INT, PTR, SIZE_T, SIZE_T, UNDEF}, INT, handle_default32 },
	[168] = {"poll", 3, {PTR, UINT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[169] = {"nfsservctl", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[170] = {"setresgid", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[171] = {"getresgid", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[172] = {"prctl", 5, {INT, ULONG, ULONG, ULONG, ULONG, UNDEF}, INT, handle_default32 },
	[173] = {"rt_sigreturn", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[174] = {"rt_sigaction", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[175] = {"rt_sigprocmask", 4, {INT, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT, handle_default32 },
	[176] = {"rt_sigpending", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[177] = {"rt_sigtimedwait", 3, {PTR, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT, handle_default32 },
	[178] = {"rt_sigqueueinfo", 3, {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[179] = {"rt_sigsuspend", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[180] = {"pread64", 4, {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[181] = {"pwrite64", 4, {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[182] = {"chown", 3, {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[183] = {"getcwd", 2, {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR, handle_default32 },
	[184] = {"capget", 2, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[185] = {"capset", 2, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[186] = {"sigaltstack", 2, {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[187] = {"sendfile", 4, {INT, INT, UNDEF, LONG, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[188] = {"getpmsg", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[189] = {"putpmsg", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[190] = {"vfork", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[191] = {"ugetrlimit", 2, {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[192] = {"mmap2", 6, {PTR, SIZE_T, PROT, MAP, INT, HEX} , PTR, handle_default32 },
	[193] = {"truncate64", 2, {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[194] = {"ftruncate64", 2, {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[195] = {"stat64", 2, {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[196] = {"lstat64", 2, {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[197] = {"fstat64", 2, {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[198] = {"lchown32", 3, {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[199] = {"getuid32", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[200] = {"getgid32", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[201] = {"geteuid32", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[202] = {"getegid32", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[203] = {"setresuid32", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[204] = {"getresuid32", 3, {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[205] = {"getgroups32", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[206] = {"setgroups32", 2, {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[207] = {"fchown32", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[208] = {"setresuid32", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[209] = {"getresuid32", 3, {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[210] = {"setresgid32", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[211] = {"getresgid32", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[212] = {"chown32", 3, {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[213] = {"setuid32", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[214] = {"getuid32", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[215] = {"setfsuid32", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[216] = {"setfsgid32", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[217] = {"pivot_root", 2, {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[218] = {"mincore", 3, {PTR, SIZE_T, STR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[219] = {"madvise", 3, {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[220] = {"getdents64", 3, {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[221] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[222] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[223] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[224] = {"gettid", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[225] = {"readahead", 3, {INT, LONG, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[226] = {"setxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[227] = {"lsetxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[228] = {"fsetxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[229] = {"getxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[230] = {"lgetxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[231] = {"fgetxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[232] = {"listxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[233] = {"llistxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[234] = {"flistxattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[235] = {"removexattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[236] = {"lremovexattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[237] = {"fremovexattr", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[238] = {"tkill", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[239] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[240] = {"futex", 6, {PTR, INT, INT, PTR, PTR, INT}, INT, handle_default32 },
	[241] = {"sched_setaffinity", 3, {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[242] = {"sched_getaffinity", 3, {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[243] = {"set_thread_area", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[244] = {"get_thread_area", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[245] = {"io_setup", 2, {UINT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[246] = {"io_destroy", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[247] = {"io_getevents", 5, {INT, LONG, LONG, PTR, PTR, UNDEF}, INT, handle_default32 },
	[248] = {"io_submit", 3, {INT, LONG, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[249] = {"io_cancel", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[250] = {"fadvise64", 4, {INT, INT, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[251] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[252] = {"exit_group", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[253] = {"lookup_dcookie", 3, {ULONG, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[254] = {"epoll_create", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[255] = {"epoll_ctl", 4, {INT, INT, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[256] = {"epoll_wait", 4, {INT, PTR, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[257] = {"remap_file_pages", 5, {PTR, SIZE_T, PROT, SIZE_T, INT, UNDEF}, INT, handle_default32 },
	[258] = {"set_tid_address", 1, {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[259] = {"timer_create", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[260] = {"timer_settime", 4, {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[261] = {"timer_gettime", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[262] = {"timer_getoverrun", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[263] = {"timer_delete", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[264] = {"clock_settime", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF} , INT, handle_default32 },
	[265] = {"clock_gettime", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[266] = {"clock_getres", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[267] = {"clock_nanosleep", 4, {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[268] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[269] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[270] = {"tgkill", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[271] = {"utimes", 2, {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[273] = {"vserver", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[274] = {"mbind", 6, {PTR, ULONG, INT, PTR, ULONG, UINT}, LONG, handle_default32 },
	[275] = {"get_mempolicy", 5, {INT, PTR, ULONG, PTR, ULONG, UNDEF}, INT, handle_default32 },
	[276] = {"set_mempolicy", 3, {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[277] = {"mq_open", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[278] = {"mq_unlink", 1, {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[279] = {"mq_timedsend", 5, {INT, STR, SIZE_T, UINT, PTR, UNDEF}, INT, handle_default32 },
	[280] = {"mq_timedreceive", 5, {INT, STR, SIZE_T, UINT, PTR, UNDEF}, SSIZE_T, handle_default32 },
	[281] = {"mq_notify", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[282] = {"mq_getsetattr", 3, {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[283] = {"kexec_load", 4, {ULONG, ULONG, PTR, ULONG, UNDEF, UNDEF}, LONG, handle_default32 },
	[284] = {"waitid", 4, {INT, INT, PTR, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[285] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[286] = {"add_key", 4, {STR, STR, PTR, SIZE_T, LONG, UNDEF}, LONG, handle_default32 },
	[287] = {"request_key", 4, {STR, STR, STR, LONG, UNDEF, UNDEF}, LONG, handle_default32 },
	[288] = {"keyctl", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[289] = {"ioprio_set", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[290] = {"ioprio_get", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[291] = {"inotify_init", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[292] = {"inotify_add_watch", 3, {INT, STR, UINT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[293] = {"inotify_rm_watch", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[294] = {"migrate_pages", 4, {INT, ULONG, PTR, PTR, UNDEF, UNDEF}, LONG, handle_default32 },
	[295] = {"openat", 4, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_openat32 },
	[296] = {"mkdirat", 3, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[297] = {"mknodat", 4, {INT, STR, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[298] = {"fchownat", 5, {INT, STR, UINT, INT, INT, UNDEF}, INT, handle_default32 },
	[299] = {"futimesat", 3, {INT, STR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[300] = {NULL, 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[301] = {"unlinkat", 3, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[302] = {"renameat", 4, {INT, STR, INT, STR, UNDEF, UNDEF}, INT, handle_default32 },
	[303] = {"linkat", 5, {INT, STR, INT, STR, INT, UNDEF}, INT, handle_default32 },
	[304] = {"symlinkat", 3, {STR, INT, STR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[305] = {"readlinkat", 4, {INT, STR, STR, SIZE_T, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[306] = {"fchmodat", 3, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[307] = {"faccessat", 3, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[308] = {"pselect6", 6, {INT, PTR, PTR, PTR, PTR, PTR} , INT, handle_default32 },
	[309] = {"ppoll", 4, {PTR, UINT, PTR, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[310] = {"unshare", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[311] = {"set_robust_list", 2, {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[312] = {"get_robust_list", 3, {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, LONG, handle_default32 },
	[313] = {"splice", 6, {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T, handle_default32 },
	[314] = {"sync_file_range", 4, {INT, LONG, LONG, UINT, UNDEF, UNDEF}, INT, handle_default32 },
	[315] = {"tee", 4, {INT, INT, SIZE_T, UINT, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[316] = {"vmsplice", 4, {INT, PTR, ULONG, UINT, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[317] = {"move_pages", 6, {INT, ULONG, PTR, INT, INT, INT}, LONG, handle_default32 },
	[318] = {"getcpu", 3, {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[319] = {"epoll_pwait", 5, {INT, PTR, INT, INT, PTR, UNDEF}, INT, handle_default32 },
	[320] = {"utimensat", 4, {INT, STR, PTR, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[321] = {"signalfd", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[322] = {"timerfd_create", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[323] = {"eventfd", 2, {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[324] = {"fallocate", 4, {INT, INT, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[325] = {"timerfd_settime", 4, {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[326] = {"timerfd_gettime", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[327] = {"signalfd4", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[328] = {"eventfd2", 2, {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[329] = {"epoll_create1", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[330] = {"dup3", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[331] = {"pipe2", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[332] = {"inotify_init1", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[333] = {"preadv", 4, {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[334] = {"pwritev", 5, {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[335] = {"rt_tgsigqueueinfo", 4, {INT, INT, INT, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[336] = {"perf_event_open", 5, {PTR, INT, INT, INT, ULONG, UNDEF}, INT, handle_default32 },
	[337] = {"recvmmsg", 5, {INT, PTR, UINT, UINT, PTR, UNDEF}, INT, handle_default32 },
	[338] = {"fanotify_init", 2, {UINT, UINT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[339] = {"fanotify_mark", 5, {INT, UINT, ULONG, INT, STR, UNDEF}, INT, handle_default32 },
	[340] = {"prlimit64", 4, {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT, handle_default32 },
	[341] = {"name_to_handle_at", 5, {INT, STR, PTR, INT, INT, UNDEF}, INT, handle_default32 },
	[342] = {"open_by_handle_at", 5, {INT, STR, PTR, INT, INT, UNDEF}, INT, handle_default32 },
	[343] = {"clock_adjtime", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[344] = {"syncfs", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[345] = {"sendmmsg", 4, {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT, handle_default32 },
	[346] = {"setns", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[347] = {"process_vm_readv", 6, {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T, handle_default32 },
	[348] = {"process_vm_writev", 6, {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T, handle_default32 },
	[349] = {"kcmp", 5, {INT, INT, INT, ULONG, ULONG, UNDEF} , INT, handle_default32 },
	[350] = {"finit_module", 3, {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[351] = {"sched_setattr", 3, {INT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[352] = {"sched_getattr", 4, {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT, handle_default32 },
	[353] = {"renameat2", 5, {INT, STR, INT, STR, UINT, UNDEF}, INT, handle_default32 },
	[354] = {"seccomp", 3, {UINT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[355] = {"getrandom", 3, {STR, SIZE_T, UINT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[356] = {"memfd_create", 2, {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[357] = {"bpf", 3, {INT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[358] = {"execveat", 5, {INT, STR, STR, STR, INT, UNDEF}, INT, handle_default32 },
	[359] = {"socket", 3, {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[360] = {"socketpair", 4, {INT, INT, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[361] = {"bind", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[362] = {"connect", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[363] = {"listen", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[364] = {"accept4", 4, {INT, PTR, PTR, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[365] = {"getsockopt", 5, {INT, INT, INT, PTR, INT, UNDEF}, INT, handle_default32 },
	[366] = {"setsockopt", 5, {INT, INT, INT, PTR, INT, UNDEF}, INT, handle_default32 },
	[367] = {"getsockname", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[368] = {"getpeername", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[369] = {"sendto", 6, {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T, handle_default32 },
	[370] = {"sendmsg", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[371] = {"recvfrom", 6, {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T, handle_default32 },
	[372] = {"recvmsg", 3, {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T, handle_default32 },
	[373] = {"shutdown", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[374] = {"userfaultfd", 0, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID, handle_default32 },
	[375] = {"membarrier", 2, {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[376] = {"mlock2", 3, {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[377] = {"copy_file_range", 6, {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T, handle_default32 },
	[378] = {"preadv2", 5, {INT, PTR, INT, LONG, INT, UNDEF}, SSIZE_T, handle_default32 },
	[379] = {"pwritev2", 5, {INT, PTR, INT, LONG, INT, UNDEF}, SSIZE_T, handle_default32 },
	[380] = {"pkey_mprotect", 4, {PTR, SIZE_T, INT, INT, UNDEF, UNDEF}, INT, handle_default32 },
	[381] = {"pkey_alloc", 2, {ULONG, ULONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[382] = {"pkey_free", 1, {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
	[383] = {"statx", 5, {INT, STR, INT, UINT, STRUCT, UNDEF}, INT, handle_default32 },
	[384] = {"arch_prctl", 2, {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT, handle_default32 },
};

#endif
