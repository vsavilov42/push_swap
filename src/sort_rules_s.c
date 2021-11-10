/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:08:35 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 18:08:36 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list **lst, int check)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst)->next)
		return ;
	tmp2 = *lst;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	*lst = tmp;
	(*lst)->next = tmp2;
	if (check == 1)
		write (1, "sa\n", 3);
}

void	sb(t_list **lst, int check)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst)->next)
		return ;
	tmp2 = *lst;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	*lst = tmp;
	(*lst)->next = tmp2;
	if (check == 1)
		write (1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	write(1, "ss\n", 3);
}
