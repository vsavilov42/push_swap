#include "../include/push_swap.h"

void	sort_chunks(t_list **lst_a, t_list **lst_b, int max)
{
	int maxtmp;
	int	chunksize;
	int	minichunk;
	int	tpa;
	int num;
	t_list *tmp;

	tpa = 0;
	num = max - 5;
	chunksize = num / 12 + 22;
	maxtmp = max;
	minichunk = max - chunksize;
	while (max > 5)
	{
			//printf("------>AAA %d\n", (*lst_a)->num);
			//printf("------>BBB %d\n", num);
		if ((*lst_a)->num < num && (*lst_a)->num <= chunksize)
		{
			pb(lst_a, lst_b);
			max--;
			tmp = *lst_a;
		}
		while (tmp)
		{
			if (tmp->num < num && tmp->num <= chunksize)
				break ;
			tpa++;
			tmp = tmp->next;
		}
		if (max == minichunk)
		{
			minichunk -= chunksize;
			chunksize += chunksize;
		}
		//	printf("---->TPA ES :%d\n", tpa);
		if (max > 5)
		{	
			if (tpa < (max / 2))
				while (tpa != 0)
				{
					ra(lst_a, 1);
					tpa--;
				}
			else
				while (tpa != 0)
				{
					rra(lst_a, 1);
					tpa--;
				}
		}
	}
	sort_five(lst_a, lst_b);
	/*while (maxtmp != 0)
	{
		sort_two(lst_a);
		if ((maxtmp - 1) == lastnum)
			maxtmp--;
		if ((*lst_b)->num == (maxtmp - 1))
		{
			pa(lst_a, lst_b);
			maxtmp--;
			tmp = *lst_b;
			tpa = 0;
		}
		while (tmp && maxtmp != (*lst_b)->num)
		{
			if (tmp->num == (maxtmp - 1))
				break ;
			tpa++;
			tmp = tmp->next;
		}
			if (tpa < maxtmp / 2)
				while (--tpa != -1)
					rb(lst_b, 1);
			else if (tpa >= maxtmp / 2)
				while (--tpa != -1)
					rrb(lst_b, 1);
	}
	pa(lst_a, lst_b);
	sort_two(lst_a);*/
}
