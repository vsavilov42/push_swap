#include "../include/push_swap.h"

void	sort_big_chunks(t_list **lst_a, t_list **lst_b, int m)
{
	t_chunk	ck;
	t_list *tmp;

	ck = (t_chunk){0, -1, 0, m / 10 + 22, 39};
	while (++ck.num < m)
	{
		tmp = *lst_a;
		if (ck.num == ck.chunksize)
			ck.chunksize += ck.halfchunk;
		while ((*lst_a)->num > ck.chunksize)
			ra(lst_a, 1);
		if ((*lst_a)->num <= ck.chunksize)
			pb(lst_a, lst_b);
	}
	sort_big_chunks_b_to_a(lst_a, lst_b);
}

void	sort_big_chunks_b_to_a(t_list **lst_a, t_list **lst_b)
{
	t_chunk ck;

	ck = (t_chunk){0, ft_lstsize(*lst_b), 0, 0, 0};
	while (--ck.num > -1)
	{
		ck.tpa = 0;
		ck.tpa = where_is_num(lst_b, ck.num, ck.tpa);
		if (ck.tpa <= ck.num / 2)
			ck.check = b_to_a_rb(lst_a, lst_b, ck.num, ck.check);
		else
			ck.check = b_to_a_rrb(lst_a, lst_b, ck.num, ck.check);
		pa(lst_a, lst_b);
		if (ck.check == 1)
		{
			sa(lst_a, 1);
			ck.check = 0;
			ck.num--;
		}
	}
}
