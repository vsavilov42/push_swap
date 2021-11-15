/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:49:10 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 11:49:11 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		max;
	int		*n;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (argv[++i][0] == '\0')
		exit(errormsg());
	lst_a = NULL;
	lst_b = NULL;
	max = 0;
	n = strtonum(stringerror(parse(argv, argc)));
	while (n[max] != -1)
		max++;
	lst_a = intolist(n, lst_a);
	if (fix_troll(&lst_a) == 0)
		exit(1);
	sort_list(&lst_a, &lst_b, max);
	free(n);
	ft_lstclear(&lst_a);
	free(lst_a);
	return (0);
}

int	fix_troll(t_list **lst_a)
{
	if (sorted(lst_a) == 1)
		return (0);
	else
		return (1);
}
