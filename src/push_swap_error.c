#include "../include/push_swap.h"

char *stringerror(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if (!(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
			exit(errormsg());
	}
	return (str);
}

char **strspliterror(char *str)
{
	char **num;

	num = ft_split(str, ' ');
	return (num);
}
