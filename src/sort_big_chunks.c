#include "../include/push_swap.h"

void	sort_big_chunks(t_list **lst_a, t_list **lst_b, int m)
{
	t_chunk	ck;
	t_list *tmp;

	ck = (t_chunk){0, -1, 0, (m / 13) + 22, (m / 13) + 22};
	if (ck.chunksize % 2 == 0)
		ck.chunksize++;
	while (++ck.num < m)
	{
		tmp = *lst_a;
		while (tmp)
		{
			if (tmp->num <= ck.chunksize)
				break ;
			ck.tpa++;
			tmp = tmp->next;
		}
		if (ck.num == ck.chunksize)
			ck.chunksize += ck.halfchunk;
		while ((*lst_a)->num > ck.chunksize)
			rra(lst_a, 1);
		if ((*lst_a)->num <= ck.chunksize)
		{
		pb(lst_a, lst_b);
		if (ck.num >= ck.chunksize - (ck.halfchunk / 2))
			rb(lst_b, 1);
		}
	}
		list(lst_a, lst_b);
	sort_big_chunks_b_to_a(lst_a, lst_b);
}

void	sort_big_chunks_b_to_a(t_list **lst_a, t_list **lst_b)
{
	t_chunk ck;

	ck = (t_chunk){0, ft_lstsize(*lst_b), 0, 0, 0};
	//	printf("NUMERO QUE ESTOY BUSCANDO: (ck.num)--> %d\n", ck.num);
	//460 < 470
	while (--ck.num > -1)
	{
		//printf("NUMERO QUE HAY EN LA LISTA: (*lst_b)->num == %d\n", (*lst_b)->num);
		//printf("NUMERO TPA: (ck.tpa) == %d\n", ck.tpa);
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
	//	list(lst_a, lst_b);
}
