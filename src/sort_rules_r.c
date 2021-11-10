/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:09:19 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 18:09:20 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_list **lst, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	second = (*lst)->next;
	while (last->next)
		last = last->next;
	*lst = second;
	first->next = NULL;
	last->next = first;
	if (check == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **lst, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	second = (*lst)->next;
	while (last->next)
		last = last->next;
	*lst = second;
	first->next = NULL;
	last->next = first;
	if (check == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	write(1, "rr\n", 3);
}
