#include "ft_strace.h"

static int print_param(pid_t pid, t_sys sys, \
						unsigned long long int reg_param[])
{
    char                    *tmp[3];
    int                     val;

    tmp[0] = get_format(sys.typearg[0], reg_param[0], pid);
    tmp[1] = get_entries(pid, reg_param[1], reg_param[2], reg_param[3]);
    tmp[2] = get_format(sys.typearg[2], reg_param[2], pid);
    val = dprintf(2, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
    for (int i = 0; i < 3; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    return (val);
}

int            handle_getdents(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
	unsigned long long int	reg_param[] = {regs.rdi, regs.rsi, regs.rdx, regs.rax};

	return (print_param(pid, sys, reg_param));
}

int            handle_getdents32(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
	unsigned long long int	reg_param[] = {regs.rbx, regs.rcx, regs.rdx, regs.rax};

	return (print_param(pid, sys, reg_param));
}
