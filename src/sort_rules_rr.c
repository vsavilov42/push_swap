#include "../include/push_swap.h"

void	rra(t_list **lst, int check)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*last;

	first = *lst;
	tmp = *lst;
	last = *lst;

	if(!(*lst)->next)
		return ;
	if ((*lst) && ft_lstsize(*lst) > 1)
	{
		while (last->next)
			last = last->next;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last->next = first;
		*lst = last;
		tmp->next = NULL;
		if (check == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **lst, int check)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*last;

	first = *lst;
	tmp = *lst;
	last = *lst;

	if(!(*lst)->next)
		return ;
	if ((*lst) && ft_lstsize(*lst) > 1)
	{
		while (last->next)
			last = last->next;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last->next = first;
		*lst = last;
		tmp->next = NULL;
		if (check == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, 0);
	rra(lst_b, 0);
	write(1, "rrr\n", 4);
}
