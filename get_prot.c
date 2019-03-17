#include "ft_strace.h"
#include <sys/mman.h>

char            *get_prot(unsigned long addr)
{
    char *ret;

    addr = addr & 7;
    switch (addr) {
        case PROT_NONE:
            ret = strdup("PROT_NONE");
            break ;
        case PROT_READ:
            ret = strdup("PROT_READ");
            break ;
        case PROT_WRITE:
            ret = strdup("PROT_WRITE");
            break ;
        case PROT_READ|PROT_WRITE:
            ret = strdup("PROT_READ|PROT_WRITE");
            break ;
        case PROT_EXEC:
            ret = strdup("PROT_EXEC");
            break ;
        case PROT_READ|PROT_EXEC:
            ret = strdup("PROT_READ|PROT_EXEC");
            break ;
        case PROT_WRITE|PROT_EXEC:
            ret = strdup("PROT_WRITE|PROT_EXEC");
            break ;
        case PROT_READ|PROT_WRITE|PROT_EXEC:
            ret = strdup("PROT_READ|PROT_WRITE|PROT_EXEC");
            break ;
        default:
            ret = strdup("???");
            break ;
    }
    return (ret);
}
