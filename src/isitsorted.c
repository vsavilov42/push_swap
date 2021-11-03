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

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	if (lst == NULL)
		return (0);
	while (lst && ++size)
		lst = lst->next;
	return (size);
}
