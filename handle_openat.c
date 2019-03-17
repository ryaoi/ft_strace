#include "ft_strace.h"


static int		print_param(pid_t pid, t_sys sys, \
							unsigned long long int reg_param[])
{
    char                    *tmp[3];
    char                    *ret;
    int                     val;

    if ((int)reg_param[0] == AT_FDCWD)
        tmp[0] = strdup("AT_FDCWD");
    else
        tmp[0] = strdup("");
    tmp[1] = get_string(pid, reg_param[1]);
    tmp[2] = get_flags(reg_param[2]);
    val = asprintf(&ret, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
    dprintf(2, "%s", ret);
    for (int i = 0; i < 3; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    if (val != -1)
    	free(ret);
    return (val);

}

int            handle_openat(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rdi, regs.rsi, regs.rdx};

    return (print_param(pid, sys, reg_param));
}

int            handle_openat32(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rbx, regs.rcx, regs.rdx};

    return (print_param(pid, sys, reg_param));
}
