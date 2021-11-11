#include "../include/push_swap.h"

t_list	*intolist(int *n, t_list *lst)
{
	t_form	varl;

	varl.i = 0;
	lst = ft_lstnew(n[varl.i]);
	while (n[++varl.i] != -1)
	{
		ft_lstadd_back(&lst, ft_lstnew(n[varl.i]));
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int num)
{
	t_list *list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (0);
	list->num = num;
	list->next = NULL;
	return (list);
}

void	ft_lstclear(t_list **lst)
{
	void	*last;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		last = *lst;
		*lst = (*lst)->next;
		free(last);
	}
	*lst = NULL;
}
