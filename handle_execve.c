#include "ft_strace.h"


static int print_param(pid_t pid, t_sys sys, \
						unsigned long long int reg_param[])
{
    char *tmp[3];
    int  ret;

    tmp[0] = get_string(pid, reg_param[0]);
    tmp[1] = get_args(pid, reg_param[1]);
    tmp[2] = get_vars(pid, reg_param[2]);

    ret = dprintf(2, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
    for (int i = 0; i < 3; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    return (ret);
}

int 		handle_execve(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rdi, regs.rsi, regs.rdx};

    return (print_param(pid, sys, reg_param));
}

int 		handle_execve32(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rbx, regs.rcx, regs.rdx};

    return (print_param(pid, sys, reg_param));
}
