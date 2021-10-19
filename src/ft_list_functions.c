#include "../include/push_swap.h"

t_list	*intolist(int *n)
{
	t_form	varl;
	t_list	lst;

	varl.i = 0;
	if (!n)
		return (NULL);
	lst.num = ft_lstnew(n[varl.i]);
	while (n[++varl.i] != -1)
	varl.i = -1;
	{
		ft_lstadd_back(lst, n[varl.i]);
	}
}

void	ft_lstadd_back(t_list **lst, t_list new)
{
	if (!lst || !new)
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

t_list	*ft_lstnew(int content)
{
	t_list *list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
