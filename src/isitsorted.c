#include "../include/push_swap.h"

int	sorted(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->next && (tmp->num) < (tmp->next->num))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	if (lst == NULL)
		return (0);
	while (lst && ++size)
		lst = lst->next;
	return (size);
}

void	sort_less_ten(t_list **lst_a, t_list **lst_b)
{
	t_chunk	ck;

	ck = (t_chunk){0, 0, 0, ft_lstsize(*lst_a), ft_lstsize(*lst_b)};
	while (ck.num < ck.chunksize - 1)
	{
		if ((*lst_a)->num == ck.num)
		{
			pb(lst_a, lst_b);
			ck.num++;
		}
		ra(lst_a, 1);
	}
	ck.halfchunk = ft_lstsize(*lst_b);
	while (ck.halfchunk > 0)
	{
		if ((*lst_b)->num == ck.halfchunk - 1)
		{
			pa(lst_a, lst_b);
			ck.halfchunk--;
		}
		rb(lst_b, 1);
	}
}
