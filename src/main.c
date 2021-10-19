#include "../include/push_swap.h"

void	leak(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv)
{
	s_list num;
	int *n;
	int i;

	//atexit(leak);
	if (argc < 2)
		return (0);
	i = -1;
	n = strtonum(stringerror(parse(argv, argc)));
	num = intolist(n);
	//into list
	//sort 3
	//sort 5
	//sort > 100
	//sort > 500
	//sort < 500
	while (n[++i] != -1)
		printf(" -> %d", n[i]);
	free(n);
	return (0);
}
