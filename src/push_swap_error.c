#include "../include/push_swap.h"

char *stringerror(char *s)
{
	int i;

	i = -1;
	while(s[++i])
	{
		if (!(s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')
			|| (s[i] == '-' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] == ' ')
			|| (s[i] == '+' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] == ' ')))
			exit(errormsg());
	}
	return (s);
}

int *strsplitatoi(char *str)
{
	char **num;
	int i;
	int j;
	int *n;

	i = -1;
	j = -1;
	n = malloc(sizeof(int) * countword(str, ' '));
	num = ft_split(str, ' ');
	while (num[++i])
	{
		n[i] = ft_atoi(num[i]);
	//	printf("%s\n", num[i]);
		free(num[i]);
	}
	free(str);
	free(num);
	return (n);
}

int *checkduples(int *n)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < countwords())
	return (n);
}
