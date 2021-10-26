#include "../include/push_swap.h"

void	leak(void)
{
	system("leaks a.out");
}
int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*tmp; //borrar in the future
	t_list	*tmp2;
	int max;
	int *n;
	int i;

	//atexit(leak);
	if (argc < 2)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	i = -1;
	max = 0;
	n = strtonum(stringerror(parse(argv, argc)));
	while (n[++i] != -1)
		printf(" -> %d\n", n[i]);
	while (n[max] != -1)
			max++;
	lst_a = intolist(n, lst_a);
	//if (max < 5)
	sortlessfive(&lst_a, &lst_b, max);
	//sort 2,3
	//sort 5
	//sort > 100
	//sort > 500
	//sort < 500
	
	//ESTE WHILE GENERA UN LEAK POR CADA ITERACION
	tmp = lst_a;
	tmp2 = lst_b;	
	while (tmp)
	{
		printf("STACK: A %d\n", tmp->num);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		printf("STACK: B %d\n", tmp2->num);
		tmp2 = tmp2->next;
	}
	printf(" \nMAX %d", max);
	free(n);
	ft_lstclear(&lst_a);
	free(lst_a);
	return (0);
}
