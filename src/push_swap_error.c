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
	int *n;
	int j;
	int nwords;
// 28 lines hacer struct.
	i = -1;
	nwords = countword(str, ' ');
	n = malloc(sizeof(int) * nwords);
	num = ft_split(str, ' ');
	while (num[++i])
	{
		n[i] = ft_atoi(num[i]);
		printf("%d\n", n[i]); //num
		free(num[i]);
	}
	i = -1;
	j = -1;
	while (++i < nwords)
	{
		while (++j < nwords)
			if (n[i] == n[j] && i != j)
				exit(errormsg());
		j = -1;
	}
	free(str);
	free(num);
	return (n);
}
