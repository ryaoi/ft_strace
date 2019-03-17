#include "ft_strace.h"

static int		print_param(pid_t pid, t_sys sys, \
							unsigned long long int reg_param[])
{
    char                    *tmp[3];
    char                    *ptr;
    int                     val;

    tmp[0] = get_format(sys.typearg[0], reg_param[0], pid);
    tmp[1] = get_string(pid, reg_param[1]);
    if (strlen(tmp[1]) > 32)
    {
        ptr = tmp[1];
        if (!(asprintf(&(tmp[1]), "%.33s\"...", ptr)))
        {
        	if (tmp[0])
        		free(tmp[0]);
        	return (-1);
        }
        free(ptr);
    }
    tmp[2] = get_format(sys.typearg[2], reg_param[2], pid);
    val = dprintf(2, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
    for (int i = 0; i < 3; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    return (val);
}

int            handle_write(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
	unsigned long long int	reg_param[] = {regs.rdi, regs.rsi, regs.rdx};

	return (print_param(pid, sys, reg_param));
}

int            handle_write32(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
	unsigned long long int	reg_param[] = {regs.rbx, regs.rcx, regs.rdx};

	return (print_param(pid, sys, reg_param));
}
