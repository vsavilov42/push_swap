/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:10:04 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/06 18:40:05 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*stringerror(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')
				|| (s[i] == '-' && s[i + 1] >= '0'
					&& s[i + 1] <= '9' && s[i - 1] == ' ')
				|| (s[i] == '+' && s[i + 1] >= '0'
					&& s[i + 1] <= '9' && s[i - 1] == ' ')))	
			exit(errormsg());
	}
	return (s);
}

int	*strtonum(char *str)
{
	t_form	ssa;
	char	**num;

	ssa = (t_form){-1, -1, -1, 0, NULL};
	num = ft_split(str, ' ');
	while (num[++ssa.k])
		ssa.nwords++;
	ssa.n = malloc(sizeof(int) * ssa.nwords);
	if (!ssa.n)
		return (NULL);
	while (num[++ssa.i])
	{
		ssa.n[ssa.i] = ft_atoi(num[ssa.i]);
		free(num[ssa.i]);
	}
	ssa.i = -1;
	while (++ssa.i < ssa.nwords)
	{
		while (++ssa.j < ssa.nwords)
			if (ssa.n[ssa.i] == ssa.n[ssa.j] && ssa.i != ssa.j)
				exit(errormsg());
		ssa.j = -1;
	}
	free(str);
	free(num);
	return (maping(ssa.n, ssa.nwords));
}
