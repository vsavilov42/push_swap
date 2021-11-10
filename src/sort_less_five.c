/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:53:01 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 18:16:59 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_list(t_list **lst_a, t_list **lst_b, int max)
{
	if (max == 2)
		sort_two(lst_a);
	if (max == 3)
		sort_three(lst_a);
	if (max == 4)
		sort_four(lst_a, lst_b);
	if (max == 5)
		sort_five(lst_a, lst_b);
	if (max > 5 && max < 10)
		sort_less_ten(lst_a, lst_b);
	if (max > 9 && max < 500)
		sort_chunks(lst_a, lst_b);
	if (max > 499)
		sort_big_chunks(lst_a, lst_b, max);
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	int	numb;
	int	*num;

	num = two_littles(lst_a);
	numb = 2;
	while (numb > 0)
	{
		if ((*lst_a)->num == num[0] || (*lst_a)->num == num[1])
		{
			pb(lst_a, lst_b);
			numb--;
		}
		if (numb > 0)
			rra(lst_a, 1);
	}
	if (ft_lstsize(*lst_a) == 3 && (*lst_b)->num < (*lst_b)->next->num)
		sb(lst_b, 1);
	sort_three(lst_a);
	pa(lst_a, lst_b);
	pa(lst_a, lst_b);
	free(num);
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->num != 0)
		ra(lst_a, 1);
	pb(lst_a, lst_b);
	sort_three(lst_a);
	pa(lst_a, lst_b);
}

void	sort_three(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->num < tmp->next->num && tmp->num < tmp->next->next->num
		&& tmp->next->num > tmp->num && tmp->next->num > tmp->next->next->num)
	{
		rra(lst, 1);
		sa(lst, 1);
	}
	else if (tmp->num > tmp->next->num && tmp->num > tmp->next->next->num
		&& tmp->next->num < tmp->num && tmp->next->num < tmp->next->next->num)
		ra(lst, 1);
	else if (tmp->num < tmp->next->num && tmp->num > tmp->next->next->num
		&& tmp->next->num > tmp->next->next->num && tmp->next->num > tmp->num)
		rra(lst, 1);
	else if (tmp->num > tmp->next->num && tmp->num > tmp->next->next->num
		&& tmp->next->num < tmp->num && tmp->next->num > tmp->next->next->num)
	{
		sa(lst, 1);
		rra(lst, 1);
	}
	else if (tmp->num > tmp->next->num && tmp->num < tmp->next->next->num
		&& tmp->next->num < tmp->num && tmp->next->num < tmp->next->next->num)
		sa(lst, 1);
}

void	sort_two(t_list **lst)
{
	if (sorted(lst) != 1)
		sa(lst, 1);
}
