
#include "ft_strace.h"
#include <sys/mman.h>

char        *get_map(unsigned long param)
{
		static long     o_def[] = {
				MAP_SHARED, MAP_PRIVATE, MAP_32BIT, MAP_ANONYMOUS, MAP_DENYWRITE,
				MAP_EXECUTABLE, MAP_FILE, MAP_FIXED, MAP_GROWSDOWN, MAP_HUGETLB,
				MAP_LOCKED, MAP_NONBLOCK, MAP_NORESERVE, MAP_POPULATE,
				MAP_STACK
		};
		static char     *o_string_def[] = {
				"MAP_SHARED", "MAP_PRIVATE", "MAP_32BIT", "MAP_ANONYMOUS", "MAP_DENYWRITE",
				"MAP_EXECUTABLE", "MAP_FILE", "MAP_FIXED", "MAP_GROWSDOWN", "MAP_HUGETLB",
				"MAP_LOCKED", "MAP_NONBLOCK", "MAP_NORESERVE", "MAP_POPULATE",
				"MAP_STACK"
		};
		char			*ret;
		char			*tmp;

		ret = NULL;
		for (size_t i = 0; i < (sizeof(o_def) / sizeof(o_def[0])); i++)
		{
				if (param & o_def[i])
				{
						if (ret == NULL)
						{
								ret = strdup(o_string_def[i]);
						}
						else
						{
								tmp = ret;
								asprintf(&ret, "%s|%s", tmp, o_string_def[i]);
								free(tmp);
						}
				}
		}
		return (ret);
}
