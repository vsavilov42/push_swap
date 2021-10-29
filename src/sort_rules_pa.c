#include "../include/push_swap.h"

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_a;
	t_list	*first_b;

	first_a = *lst_a;
	first_b = *lst_b;
	if (!(*lst_a))
		return ;
	*lst_a = (*lst_a)->next;
	if (!(*lst_b))
	{
		*lst_b = first_a;
		first_a->next = NULL;
	}
	else
	{
		*lst_b = first_a;
		first_a->next = first_b;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_a;
	t_list	*first_b;

	first_a = *lst_a;
	first_b = *lst_b;
	if (!(*lst_b))
		return ;
	*lst_b = (*lst_b)->next;
	if (!(*lst_a))
	{
		*lst_a = first_b;
		first_b->next = NULL;
	}
	else
	{
		*lst_a = first_b;
		first_b->next = first_a;
	}
	write(1, "pa\n", 3);
}
