#include "../include/push_swap.h"

void	rra(t_list **lst)
{
	t_list	*first;
	t_list	*prevlast;
	t_list	*last;
	
	if(!(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	prevlast = *lst;
	while (last->next)
		last = last->next;
	while (prevlast->next->next != NULL)
			prevlast = prevlast->next;
	last->next = first;
	*lst = last;
	prevlast->next = NULL;
}

void	rrb(t_list **lst)
{
	t_list *first;
	t_list *prevlast;
	t_list *last;

	if(!(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	prevlast = *lst;
	while (prevlast->next)
		if (prevlast->next->next != NULL)
			prevlast = prevlast->next;
	last->next = first;
	*lst = last;
	prevlast->next = NULL;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a);
	rra(lst_b);
}
