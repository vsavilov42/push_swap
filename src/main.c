#include "../include/push_swap.h"

void	leak(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int max;
	int *n;

	//atexit(leak);
	if (argc < 2)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	max = 0;
	n = strtonum(stringerror(parse(argv, argc)));
	while (n[max] != -1)
			max++;
	lst_a = intolist(n, lst_a);
	if (fix_troll(&lst_a) == 0)
		exit(1);
	sort_list(&lst_a, &lst_b, max);	
	//list(&lst_a, &lst_b);
	free(n);
	ft_lstclear(&lst_a);
	free(lst_a);
	return (0);
}

int fix_troll(t_list **lst_a)
{
	if (sorted(lst_a) == 1)
		return (0);
	else
		return (1);
}
