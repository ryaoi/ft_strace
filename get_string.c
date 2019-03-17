#include "ft_strace.h"

char        *get_string(pid_t pid, unsigned long addr)
{
    char    *str;
    char    *ret;
    int     allocated;
    int     read;
    unsigned long tmp;

    read = 0;
    allocated = PATH_MAX;
    if (!(str = malloc(PATH_MAX)))
        return (NULL);
    bzero(str, PATH_MAX);
    while (1)
    {
        if ((int)(read + sizeof(tmp)) > allocated)
        {
            allocated *= 2;
            if (!(str = realloc(str, allocated)))
                return (NULL);
        }
        tmp = ptrace(PTRACE_PEEKDATA, pid, addr + read);
        if (errno != 0)
        {
            str[read] = 0;
            break ;
        }
        memcpy(str + read, &tmp, sizeof(tmp));
        if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
            break ;
        read += sizeof(tmp);
    }
    asprintf(&ret, "\"%s\"", str);
    free(str);
    return (ret);
}
