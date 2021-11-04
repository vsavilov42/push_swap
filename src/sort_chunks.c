#include "../include/push_swap.h"

void	sort_chunks(t_list **lst_a, t_list **lst_b, int max)
{
	sort_chunks_a_to_b(lst_a, lst_b, max);
	sort_five(lst_a, lst_b);
	sort_chunks_b_to_a(lst_a, lst_b, max);
}

void	sort_chunks_a_to_b(t_list **lst_a, t_list **lst_b, int m)
{
	t_chunk	ck;
	t_list	*tmp;

	ck = (t_chunk){0, m - 5, m, (m - 5) / 7 + 22, m - ((m - 5) / 7 + 22)};
	while (m > 5)
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
		if (m == ck.minichunk)
		{
			ck.minichunk -= ck.chunksize;
			ck.chunksize += ck.chunksize;
		}
		sort_chunks_rotate_list_a(lst_a, lst_b, m, ck.tpa);
		pb(lst_a, lst_b);
		m--;
	}
}

void	sort_chunks_rotate_list_a(t_list **lst_a,
			t_list **lst_b, int max, int tpa)
{
	if (max > 5)
	{
		if (tpa < (max / 2))
		{
			while (tpa > 0)
			{
				ra(lst_a, 1);
				tpa--;
			}
		}
		else
		{
			while (tpa != 0)
			{
				if ((*lst_b)->num == max - 6)
					break ;
				rra(lst_a, 1);
				tpa--;
			}
		}
	}
}

/*void list(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst_a;
	tmp2 = *lst_b;
	while (tmp)
	{
		printf("STACK: A %d\n", tmp->num);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		printf("STACK: B %d\n", tmp2->num);
		tmp2 = tmp2->next;
	}
}*/

void	sort_chunks_b_to_a(t_list **lst_a, t_list **lst_b, int max)
{
	int		num;
	int		tpa;
	t_list	*tmp;
	int check;

	check = 0;
	tpa = 0;
	tmp = *lst_b;
	num = max - 5;
	while (num > 0)
	{
		if (check == 1)
			check = 2;
		if (check == 0)
			num = ft_lstsize(*lst_b);
		tmp = *lst_b;
		while (tmp && check != 1)
		{
			if (tmp->num == (num - 1))
				break ;
			tpa++;
			tmp = tmp->next;
		}
		if (num > 0)
		{	
			if (tpa <= (num / 2))
			{
				while (tpa > 0 && tpa--)
				{
					if ((*lst_b)->num == num - 2 && check == 0)
					{
						check = 1;
						break ;
					}
					if ((*lst_b)->num == num - 1)
					{
						tpa = 0;
						break ;
					}
					rb(lst_b, 1);
				}
			}
			else
			{
				while (tpa > 0 && tpa--)
				{
					if ((*lst_b)->num == num - 1)
					{
						tpa = 0;
						break ;
					}
					rrb(lst_b, 1);
					if ((*lst_b)->num == num - 2 && check == 0)
					{
						check = 1;
						break ;
					}
				}
			}
		}
		pa(lst_a, lst_b);
		if (check == 2)
		{
			sa(lst_a, 1);
			check = 0;
		}
	}
}
