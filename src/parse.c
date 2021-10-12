#include "../include/push_swap.h"

char	*parse(char **arg, int argc)
{
	int argnum;
	char *allnum;
	char *tmp;

	argnum = 0;
	allnum = ft_strdup("");
	while (++argnum < argc)
	{
		tmp = ft_strjoin(allnum, arg[argnum]);
		free(allnum);
		allnum = tmp;
		tmp = ft_strjoin(allnum, " ");
		free(allnum);
		allnum = tmp;
	}
	return (allnum);
}
