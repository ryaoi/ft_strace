#include "ft_strace.h"

static void	free_args(char **args, int max)
{
    for (int i = 0; i < max; i++)
    {
    	if (args[i])
        	free(args[i]);
    }
}


char        *get_args(pid_t pid, unsigned long addr)
{
    char        *ret;
    char        *tmp;
    char        *args[4096];
    unsigned long   data;
    int         index;
    int         max;

    index = 0;
    while (1)
    {
        data = ptrace(PTRACE_PEEKDATA, pid, addr + (index * 8));
        args[index] = get_string(pid, data);
        if (index == 2)
            break ;
        if (strcmp(args[index], "\"\"") == 0)
            break ;
        index++;
    }
    max = index;
    if (!(asprintf(&ret, "%s", args[0])))
    {
    	free_args(args, max);
    	return (NULL);
    }
    index = 1;
    while ((strcmp(args[index], "\"\"") != 0))
    {
        tmp = ret;
        if (!(asprintf(&ret, "%s, %s", tmp, args[index])))
        {
        	free(tmp);
			free_args(args, max);
        	return (NULL);
        }
        free(tmp);
        index++;
    }
    tmp = ret;
    if (!(asprintf(&ret, "[%s]", tmp)))
    {
    	free(tmp);
    	free_args(args, max);
    	return (NULL);
    }
    free(tmp);
    free_args(args, max);
    return (ret);
}
