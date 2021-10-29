#include "../include/push_swap.h"

void	sort_chunks(t_list **lst_a, t_list **lst_b, int max)
{
	int maxtmp;
	int	chunksize;
	int	minichunk;
	int	tpa;
	t_list *tmp;

	tmp = *lst_a;
	tpa = 2;
	chunksize = max / 13 + 22;
	printf("----------->%d\n", chunksize);
	maxtmp = max;
	minichunk = max - chunksize;
	if (sorted(lst_a) != 1)
	{
		while (max != 0)
		{
			if ((*lst_a)->num < chunksize)
			{
				pb(lst_a, lst_b);
				max--;
			}
			if (max == minichunk)
			{
				minichunk -= chunksize;
				chunksize += chunksize;
			}
			if (max != 0)
				rra(lst_a, 1);
		}
		/*max = maxtmp - 1;
		chunksize = max - 2;
		minichunk = maxtmp - chunksize;
		while (max != 0)
		{
			if ((*lst_b)->num > chunksize)
			{
				pa(lst_a, lst_b);
				max--;
				tpa--;
				if (tpa == 0)
				{
					sort_two(lst_a);
					chunksize -= 2;
					tpa = 2;
				}
			}
			if (max != 0)
				rb(lst_b, 1);
		}*/
	}
}
