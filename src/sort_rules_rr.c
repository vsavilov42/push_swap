#include "../include/push_swap.h"

void	rra(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*prevlast;
	t_list	*last;
	
	if(!(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	prevlast = *lst;
	second = (*lst)->next;
	while (last->next)
		last = last->next;
	while (prevlast->next->next != NULL)
			prevlast = prevlast->next;
	last->next = first;  //0 2 1 -> 1 0 2
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
	prevlast = NULL;
}
