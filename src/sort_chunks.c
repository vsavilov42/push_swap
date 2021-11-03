#include "../include/push_swap.h"

void	sort_chunks(t_list **lst_a, t_list **lst_b, int max)
{
	sort_chunks_a_to_b(lst_a, lst_b, max);
	sort_five(lst_a, lst_b);
	sort_chunks_b_to_a(lst_a, lst_b, max);	
}

void	sort_chunks_a_to_b(t_list **lst_a, t_list **lst_b, int max)
{
	/*t_chunk ck;
	t_list	*tmp;

	ck = (t_chunk){0, max - 5, max, ck.num / 7 + 22, max - ck.chunksize};
	while (max > 5)
	{
		ck.tpa = 0;
		tmp = *lst_a;
		while (tmp)
		{
			if (tmp->num < ck.num && tmp->num <= ck.chunksize)
				break ;
			ck.tpa++;
			tmp = tmp->next;
		}
		if (max == ck.minichunk)
		{
			ck.minichunk -= ck.chunksize;
			ck.chunksize += ck.chunksize;
		}
		sort_chunks_rotate_list_a(lst_a, lst_b, max, ck.tpa);
		pb(lst_a, lst_b);
		max--;
	}*/
	///////////////////////////////////////////////////////////////
	int maxtmp;
	int	chunksize;
	int	minichunk;
	int	tpa;
	int num;
	t_list *tmp;

	tpa = 0;
	num = max - 5;
	chunksize = num / 7 + 22;
	maxtmp = max;
	minichunk = max - chunksize;
	while (max > 5)
	{
		tpa = 0;
		tmp = *lst_a;
		while (tmp)
		{
			if (tmp->num < num && tmp->num <= chunksize)
				break ;
			tpa++;
			tmp = tmp->next;
		}
		if (max == minichunk)
		{
			minichunk -= chunksize;
			chunksize += chunksize;
		}
		sort_chunks_rotate_list_a(lst_a, lst_b, max, tpa);
		pb(lst_a, lst_b);
		max--;
	}
}

void	sort_chunks_rotate_list_a(t_list **lst_a, t_list **lst_b, int max, int tpa)
{
	if (max > 5)
	{
		if (tpa < (max / 2))
			while (tpa > 0)
			{
				ra(lst_a, 1);
				tpa--;
			}
		else
			while (tpa != 0)
			{
				if ((*lst_b)->num == max - 6)
					break ;
				rra(lst_a, 1);
				tpa--;
			}
	}
}

void	sort_chunks_b_to_a(t_list **lst_a, t_list **lst_b, int max)
{
	int num;
	int tpa;
	t_list *tmp;

	tmp = *lst_b;
	num = max - 5;
	while (num > 0)
	{
		num = ft_lstsize(*lst_b);
		tpa = 0;
		tmp = *lst_b;
		while (tmp)
		{
			if (tmp->num == (num - 1))
				break ;
			tpa++;
			tmp = tmp->next;
		}
		if (num > 0)
		{	
			if (tpa < (num / 2))
				while (tpa > 0)
				{
					rb(lst_b, 1);
					tpa--;
				}
			else
				while (tpa > 0)
				{
					if ((*lst_b)->num == num - 1)
						break ;
					rrb(lst_b, 1);
					tpa--;
				}
		}
		pa(lst_a, lst_b);
	}
}
