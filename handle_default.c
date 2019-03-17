#include "ft_strace.h"

int            handle_default(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rdi, regs.rsi, regs.rdx, regs.r10, regs.r8, regs.r9};
    char                    *tmp[6];
    char                    *ret;
    int                     val;

    for (int i = 0; i < sys.nargs; i++)
        tmp[i] = get_format(sys.typearg[i], reg_param[i], pid);
    switch (sys.nargs)
    {
        case 0:
            val = asprintf(&ret, "%s()", sys.name);
            break;
        case 1:
            val = asprintf(&ret, "%s(%s)", sys.name, tmp[0]);
            break;
        case 2:
            val = asprintf(&ret, "%s(%s, %s)", sys.name, tmp[0], tmp[1]);
            break;
        case 3:
            val = asprintf(&ret, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
            break;
         case 4:
            val = asprintf(&ret, "%s(%s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3]);
            break;
         case 5:
            val = asprintf(&ret, "%s(%s, %s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
            break;
         case 6:
            val = asprintf(&ret, "%s(%s, %s, %s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
            break;
         default:
            break ;
    }
    dprintf(2, "%s", ret);
    for (int i = 0; i < sys.nargs; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    if (ret)
    	free(ret);
    return (val);
}

int            handle_default32(pid_t pid, struct user_regs_struct regs, t_sys sys)
{
    unsigned long long int reg_param[] = {regs.rbx, regs.rcx, regs.rdx, regs.rsi, regs.rdi, regs.rbp};
    char                    *tmp[6];
    char                    *ret;
    int                     val;

    for (int i = 0; i < sys.nargs; i++)
        tmp[i] = get_format(sys.typearg[i], reg_param[i], pid);
    switch (sys.nargs)
    {
        case 0:
            val = asprintf(&ret, "%s()", sys.name);
            break;
        case 1:
            val = asprintf(&ret, "%s(%s)", sys.name, tmp[0]);
            break;
        case 2:
            val = asprintf(&ret, "%s(%s, %s)", sys.name, tmp[0], tmp[1]);
            break;
        case 3:
            val = asprintf(&ret, "%s(%s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2]);
            break;
         case 4:
            val = asprintf(&ret, "%s(%s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3]);
            break;
         case 5:
            val = asprintf(&ret, "%s(%s, %s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
            break;
         case 6:
            val = asprintf(&ret, "%s(%s, %s, %s, %s, %s, %s)", sys.name, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
            break;
         default:
            break ;
    }
    dprintf(2, "%s", ret);
    for (int i = 0; i < sys.nargs; i++)
    {
    	if (tmp[i])
        	free(tmp[i]);
    }
    if (ret)
    	free(ret);
    return (val);
}
