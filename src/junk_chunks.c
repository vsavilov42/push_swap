/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:00:05 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 20:39:21 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	b_to_a_rb(t_list **lst_a, t_list **lst_b, int num, int check)
{
	while ((*lst_b)->num != num)
	{
		if ((*lst_b)->num == num - 1)
		{
			pa(lst_a, lst_b);
			check = 1;
		}
		if ((*lst_b)->num == num)
			break ;
		rb(lst_b, 1);
	}
	return (check);
}

int	b_to_a_rrb(t_list **lst_a, t_list **lst_b, int num, int check)
{
	while ((*lst_b)->num != num)
	{
		if ((*lst_b)->num == num - 1)
		{
			pa(lst_a, lst_b);
			check = 1;
		}
		if ((*lst_b)->num == num)
			break ;
		rrb(lst_b, 1);
	}
	return (check);
}

int	where_is_num(t_list **lst, int num, int tpa)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->num == num)
			break ;
		tpa++;
		tmp = tmp->next;
	}
	return (tpa);
}
