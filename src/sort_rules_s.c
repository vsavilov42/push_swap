#include "../include/push_swap.h"

void	sa(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	if (!(*lst)->next)
		return ;
	if (isitsorted(lst) != 1)
	{
	tmp2 = *lst;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	*lst = tmp;
	(*lst)->next = tmp2;
	}
}

void	sb(t_list **lst)
{
	t_list *tmp;
	t_list *tmp2;

	if (!(*lst)->next)
		return ;
	tmp2 = *lst;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	*lst = tmp;
	(*lst)->next = tmp2;
}
