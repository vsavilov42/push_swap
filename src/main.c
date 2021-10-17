#include "../include/push_swap.h"

void	leak(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv)
{
	int *n;
	int i;

	atexit(leak);
	if (argc < 2)
		return (0);
	i = -1;
	n = checkduples(strsplitatoi(stringerror(parse(argv, argc)))); //duples
	//num = doubleerror(num);
	//while (num[++i])
	//	printf("%s ", num[i]);
	free(n);
	return (0);
}
