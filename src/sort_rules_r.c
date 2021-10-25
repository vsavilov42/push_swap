#include "../include/push_swap.h"

void	ra(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*lst)->next)
		return ;	
	first = *lst;
	last = *lst;
	second = (*lst)->next;
	while (last->next)
		last = last->next;
	*lst = second;
	first->next = NULL;
	last->next = first;
}

void	rb(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*lst)->next)
		return ;	
	first = *lst;
	last = *lst;
	second = (*lst)->next;
	while (last->next)
		last = last->next;
	*lst = second;
	first->next = NULL;
	last->next = first;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
}
