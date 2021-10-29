#include "../include/push_swap.h"

int	sorted(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->next && (tmp->num) < (tmp->next->num))
			tmp = tmp->next;
		else	
			return (0);
	}
	return (1);
}
