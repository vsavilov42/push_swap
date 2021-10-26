#include "../include/push_swap.h"

void	sa(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	if (!(*lst)->next)
		return ;
	tmp2 = *lst;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	*lst = tmp;
	(*lst)->next = tmp2;
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

void	ss(t_list **lst_a, t_list **lst_b)
{
	sa(lst_a);
	sb(lst_b);
}
