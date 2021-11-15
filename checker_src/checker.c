/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:54:40 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 12:35:48 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/get_next_line.h"

static int	gnlerror(void)
{
	write(1, "KO\n", 3);
	return (1);
}

void	read_gnl(t_list **lst_a, t_list **lst_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		do_instruct(lst_a, lst_b, inst);
		free(inst);
		inst = get_next_line(0);
	}
	free(inst);
}

void	do_instruct(t_list **lst_a, t_list **lst_b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		sa(lst_a, 0);
	else if (!ft_strcmp(inst, "sb\n"))
		sb(lst_b, 0);
	else if (!ft_strcmp(inst, "ss\n"))
		ss(lst_a, lst_b);
	else if (!ft_strcmp(inst, "ra\n"))
		ra(lst_a, 0);
	else if (!ft_strcmp(inst, "rb\n"))
		rb(lst_b, 0);
	else if (!ft_strcmp(inst, "rr\n"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(inst, "rra\n"))
		rra(lst_a, 0);
	else if (!ft_strcmp(inst, "rrb\n"))
		rrb(lst_b, 0);
	else if (!ft_strcmp(inst, "rrr\n"))
		rrr(lst_a, lst_b);
	else if (!ft_strcmp(inst, "pa\n"))
		pa(lst_a, lst_b, 0);
	else if (!ft_strcmp(inst, "pb\n"))
		pb(lst_a, lst_b, 0);
	else
		exit(gnlerror());
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		*n;
	int		i;

	i = 0;
	lst_a = NULL;
	lst_b = NULL;
	if (argc < 2)
		return (0);
	n = strtonum(stringerror(parse(argv, argc)));
	lst_a = intolist(n, lst_a);
	read_gnl(&lst_a, &lst_b);
	if (sorted(&lst_a) != 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(n);
	ft_lstclear(&lst_a);
	free(lst_a);
	return (0);
}
