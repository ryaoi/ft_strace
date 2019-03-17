#include "ft_strace.h"

char        *get_vars(pid_t pid, unsigned long addr)
{
    char        *ret;
    unsigned long tmp;
    int     entries;

    entries = 0;
    while (1)
    {
        tmp = ptrace(PTRACE_PEEKDATA, pid, addr + (entries * 8));
        if (tmp == 0)
            break ;
        if (errno != 0)
        {
            break ;
        }
        entries++;
    }
    asprintf(&ret, " %#lx /* %d vars */", addr, entries);
    return (ret);
}
