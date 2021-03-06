/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:23:00 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 18:24:40 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*maping(int *n, int nnum)
{
	t_form	map;
	int		num;
	int		*aux;

	aux = malloc(sizeof(int) * (nnum + 1));
	if (!aux)
		return (NULL);
	map.i = -1;
	while (++map.i < nnum)
	{
		num = 0;
		map.j = 0;
		while (map.j < nnum)
			if (n[map.i] > n[map.j++])
				num++;
		aux[map.i] = num;
	}
	map.i = -1;
	aux[nnum] = -1;
	free(n);
	return (aux);
}
