#include "ft_strace.h"

char            *get_format(int type, unsigned long long int reg, pid_t pid)
{
    char *ret;

    switch (type) {
        case ULONG:
            if (!(asprintf(&ret, "%lu", (long unsigned int)reg)))
            	return (NULL);
            break ;
        case LONG:
            if (!(asprintf(&ret, "%ld", (long int)reg)))
            	return (NULL);
            break ;
        case UINT:
            if (!(asprintf(&ret, "%u", (unsigned int)reg)))
				return (NULL);
            break ;
        case INT:
            if (!(asprintf(&ret, "%d", (int)reg)))
            	return (NULL);
            break ;
        case SIZE_T:
            if (!(asprintf(&ret, "%lu", (unsigned long)reg)))
            	return (NULL);
            break ;
        case SSIZE_T:
            if (!(asprintf(&ret, "%ld", (long int)reg)))
            	return (NULL);
            break ;
        case PTR:
            if (reg == 0)
                ret = strdup("NULL");
            else
                if (!(asprintf(&ret, "%#llx", reg)))
                	return (NULL);
            break ;
        case STR:
            ret = get_string(pid, reg);
            break ;
        case STRUCT:
            if (!(asprintf(&ret, "%#llx", reg)))
            	return (NULL);
            break ;
        case VOID:
            ret = strdup("?");
            break ;
        case HEX:
            if (!(asprintf(&ret, "%#x", (unsigned int)reg)))
            	return (NULL);
            break ;
        case PROT:
            ret = get_prot((unsigned int)reg);
            break ;
        case FLAGS:
            ret = get_flags((unsigned int)reg);
            break ;
        case MAP:
            ret = get_map((unsigned int)reg);
            break ;
        default:
            ret = strdup("???");
            break ;
    }
    return (ret);
}
