#include "../include/push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_a;

	first_a = *lst_a;
	if (!(*lst_a))
		return ;
	*lst_a = (*lst_a)->next;
	if (!(*lst_b))
		*lst_b = ft_lstnew(first_a->num);
	else
	{
		*lst_b = (*lst_b)->next;
		*lst_b = first_a;
	}
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_b;

	first_b = *lst_b;
	if (!(*lst_b))
		return ;
	*lst_b = (*lst_b)->next;
	(*lst_a)->next = *lst_a;
	*lst_a = first_b;
}
