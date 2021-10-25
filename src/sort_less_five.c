#include "../include/push_swap.h"

void	sortlessfive(t_list **lst, int max)
{
	if (max == 2)
		if(isitsorted(lst) != 1)
			sa(lst);
	if (max == 3)
	{
		if (((*lst)->num == 0) && ((*lst)->next->num) == 2)
			rra(lst);
		if (((*lst)->num == 2) && ((*lst)->next->num) == 0)
			ra(lst);
		//if (((*lst)->num == 1) && ((*lst)->next->num) == 2)
		//	rra(lst);
		//if (((*lst)->num == 2) && ((*lst)->next->num) == 1)
		//	ra(lst);	
		//if (((*lst)->num == 1) && ((*lst)->next->num) == 0)
		//	sa(lst);
	}

}
