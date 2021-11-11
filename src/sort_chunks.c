/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:29:44 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/11 16:58:23 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_chunks(t_list **lst_a, t_list **lst_b)
{
	int	max;

	max = ft_lstsize(*lst_a);
	sort_chunks_a_to_b(lst_a, lst_b, max);
	sort_five(lst_a, lst_b);
	sort_chunks_b_to_a(lst_a, lst_b);
}

void	sort_chunks_a_to_b(t_list **lst_a, t_list **lst_b, int m)
{
	t_chunk	ck;	
	t_list	*tmp;

	ck = (t_chunk){0, 0, 0, m / 13 + 17, (m / 13 + 21) / 2};
	if (ck.chunksize % 2 == 0)
		ck.chunksize++;
	while (ck.num < m - 5)
	{
		ck.num = m - ft_lstsize(*lst_a);
		ck.tpa = 0;
		tmp = *lst_a;
		while (tmp)
		{
			if (tmp->num <= ck.chunksize && tmp->num < m - 5)
				break ;
			ck.tpa++;
			tmp = tmp->next;
		}
		if (ck.num == ck.chunksize)
			ck.chunksize += ck.halfchunk;
		sort_chunks_rotate_list_a(lst_a, m, ck.tpa, ck.chunksize);
		if ((*lst_a)->num < m - 5)
			pb(lst_a, lst_b);
	}
}

void	sort_chunks_b_to_a(t_list **lst_a, t_list **lst_b)
{
	t_chunk	ck;	

	ck = (t_chunk){0, 0, 0, 0, 0};
	ck.chunksize = ft_lstsize(*lst_b);
	ck.num = ck.chunksize;
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

void	list(t_list **lst_a, t_list **lst_b)
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
}
