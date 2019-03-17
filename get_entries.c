#include "ft_strace.h"

static void fill_data(char *stored_data, pid_t pid, \
                        unsigned long addr, unsigned int count)
{
    int             read;
    unsigned long   tmp;

    read = 0;
    bzero(stored_data, count);
    while ((int)(count) > read)
    {
        tmp = ptrace(PTRACE_PEEKDATA, pid, addr + read);
        memcpy(stored_data + read, &tmp, sizeof(tmp));
        if (errno != 0)
        {
            break ;
        }
        read += sizeof(tmp);
    }
}

static int  count_entries(char *stored_data)
{
    struct linux_dirent {
        long           d_ino;
        off_t          d_off;
        unsigned short d_reclen;
        char           d_name[];
    };

    int                     entries;
    int                     bpos;
    struct linux_dirent     *d;

    entries = 0;
    bpos = 0;
    while (1) {
        d = (struct linux_dirent *) (stored_data + bpos);
        if (d->d_reclen == 0)
            break;
        bpos += d->d_reclen;
        entries++;
    }
    return (entries); 
}


char            *get_entries(pid_t pid, unsigned long addr, \
                                unsigned int count, int rax)
{
    char        *ret;
    int         entries;
    char        stored_data[count];

    if (rax == 0)
        return (strdup("/* 0 entries */"));
    fill_data(stored_data, pid, addr, count);
    entries = count_entries(stored_data);
    asprintf(&ret, "/* %d entries */", entries);
    return (ret);
}
