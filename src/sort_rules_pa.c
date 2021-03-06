/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules_pa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:09:32 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 11:15:27 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_list **lst_a, t_list **lst_b, int check)
{
	t_list	*first_a;
	t_list	*first_b;

	first_a = *lst_a;
	first_b = *lst_b;
	if (!(*lst_a))
		return ;
	*lst_a = (*lst_a)->next;
	if (!(*lst_b))
	{
		*lst_b = first_a;
		first_a->next = NULL;
	}
	else
	{
		*lst_b = first_a;
		first_a->next = first_b;
	}
	if (check == 1)
		write(1, "pb\n", 3);
}

void	pa(t_list **lst_a, t_list **lst_b, int check)
{
	t_list	*first_a;
	t_list	*first_b;

	first_a = *lst_a;
	first_b = *lst_b;
	if (!(*lst_b))
		return ;
	*lst_b = (*lst_b)->next;
	if (!(*lst_a))
	{
		*lst_a = first_b;
		first_b->next = NULL;
	}
	else
	{
		*lst_a = first_b;
		first_b->next = first_a;
	}
	if (check == 1)
		write(1, "pa\n", 3);
}
