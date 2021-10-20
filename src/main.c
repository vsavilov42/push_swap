#include "../include/push_swap.h"

void	leak(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv)
{
	t_list *lst;
	int max;
	int *n;
	int i;

	//atexit(leak);
	if (argc < 2)
		return (0);
	lst = NULL;
	i = -1;
	max = 0;
	n = strtonum(stringerror(parse(argv, argc)));
	while (n[max] != -1)
			max++;
	lst = intolist(n, lst);
	//sort 2,3
	//sort 5
	//sort > 100
	//sort > 500
	//sort < 500
	//while (++i < max)
		printf("LIST: %d\n", lst->num);
	i = -1;
	while (n[++i] != -1)
		printf(" -> %d", n[i]);
	printf(" \nMAX %d", max);
	free(n);
	ft_lstclear(&lst);
	free(lst);
	return (0);
}
