#include "../include/push_swap.h"

void	rra(t_list **lst, int check)
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
	if (check == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **lst, int check)
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
	if (check == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, 0);
	rra(lst_b, 0);
	write(1, "rrr\n", 4);
}
