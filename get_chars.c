#include "ft_strace.h"
#include <ctype.h>

char        *get_chars(pid_t pid, unsigned long addr, int rax)
{
    char    *str;
    char    *ret;
    char    *ptr;
    int     allocated;
    int     read;
    unsigned long tmp;

    read = 0;
    allocated = PATH_MAX;
    if (!(str = malloc(PATH_MAX)))
        return (NULL);
    bzero(str, PATH_MAX);
    while (rax > read)
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
    read = 1;
    if (isprint(str[0]))
        asprintf(&ret, "%c", str[0]);
    else
        asprintf(&ret, "\\%o", str[0]);
    while (read < rax)
    {
        ptr = ret;
        if (str[read] == '\n')
            asprintf(&ret, "%s\\n", ptr);
        else if (str[read] == '\t')
            asprintf(&ret, "%s\\t", ptr);
        else if (isprint(str[read]))
            asprintf(&ret, "%s%c", ptr, str[read]);
        else
            asprintf(&ret, "%s\\%o", ptr, str[read]);
        free(ptr);
        read++;
    }
    ptr = ret;
    asprintf(&ret, "\"%s\"", ptr);
    free(ptr);
    free(str);
    return (ret);
}
