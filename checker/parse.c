/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:22:20 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/11 18:38:05 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*parse(char **arg, int argc)
{
	int		argnum;
	char	*allnum;
	char	*tmp;

	argnum = 0;
	allnum = ft_strdup(" ");
	while (++argnum < argc)
	{
		tmp = ft_strjoin(allnum, arg[argnum]);
		free(allnum);
		allnum = tmp;
		tmp = ft_strjoin(allnum, " ");
		free(allnum);
		allnum = tmp;
	}
	return (allnum);
}
