#include "../include/push_swap.h"

void	sortlessfive(t_list **lst_a, t_list **lst_b, int max)
{
	if (max == 2)
		sort_two(lst_a);
	if (max == 3)
	{
		if (((*lst_a)->num == 0) && ((*lst_a)->next->num) == 2)
			rra(lst_a);
		if (((*lst_a)->num == 2) && ((*lst_a)->next->num) == 0)
			ra(lst_a);
		if (((*lst_a)->num == 1) && ((*lst_a)->next->num) == 2)
			rra(lst_a);
		if (((*lst_a)->num == 2) && ((*lst_a)->next->num) == 1)
			ra(lst_a);	
		if (((*lst_a)->num == 1) && ((*lst_a)->next->num) == 0)
			sa(lst_a);
	}
	if (max == 4)
	{
		if (isitsorted(lst_a) != 1)
		{
			pa(lst_a, lst_b);
			pa(lst_a, lst_b);
			sort_two(lst_a);
			sort_two(lst_b);
		}
	}
}

void	sort_two(t_list **lst)
{
		if(isitsorted(lst) != 1)
			sa(lst);
}
