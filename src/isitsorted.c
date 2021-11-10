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

void	sort_big_chunks(t_list **lst_a, t_list **lst_b, int m)
{
	t_chunk	ck;
	t_list *tmp;

	ck = (t_chunk){0, -1, 0, (m / 13) + 22, (m / 13) + 12};
	while (++ck.num < m)
	{
		tmp = *lst_b;
		while (tmp)
		{
			if (tmp->num <= ck.chunksize)
				break ;
			ck.tpa++;
			tmp = tmp->next;
		}
		if (ck.num == ck.chunksize)
			ck.chunksize += ck.halfchunk;
		if (ck.tpa < m / 2)
			while (ck.tpa > 0 && ck.tpa--)
				ra(lst_a, 1);
		else
		{
			while (1)
			{
				printf("EL NUM EN A ES: %d\n", (*lst_a)->num);
				if ((*lst_a)->num <= ck.chunksize)
					break ;
				rra(lst_a, 1);
			}
		}
		if ((*lst_a)->num <= ck.chunksize)
			pb(lst_a, lst_b);
	}
	list(lst_a, lst_b);
}
