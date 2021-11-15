/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:17:34 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 11:15:02 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	errormsg(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		negative;
	size_t	i;

	i = 0;
	negative = 1;
	while ((*str >= 0x09 && *str <= 0x0d) || (*str == 0x20))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = (i * 10) + (*str - '0');
		if (i > 2147483647 && negative == 1)
			exit(errormsg());
		if (i > 2147483648 && negative == -1)
			exit(errormsg());
		str++;
	}
	return (negative * i);
}

void	sort_chunks_rotate_list_a(t_list **lst_a, int max, int tpa, int chunk)
{
	if (tpa <= (max / 2))
		while (tpa > 0 && tpa--)
			ra(lst_a, 1);
	else
	{
		while (max - tpa > 0 && tpa--)
		{
			if ((*lst_a)->num <= chunk)
				break ;
			rra(lst_a, 1);
		}
	}
}

int	*two_littles(t_list **lst)
{
	t_list	*tmp;
	int		*n;

	tmp = *lst;
	n = malloc(sizeof(int) * 2);
	n[0] = 2147483647;
	n[1] = n[0];
	while (tmp)
	{
		if (tmp->num < n[0])
			n[0] = tmp->num;
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->num < n[1] && tmp->num != n[0])
			n[1] = tmp->num;
		tmp = tmp->next;
	}
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			j;
	char			*sresult;
	unsigned int	k;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sresult = (char *)malloc(sizeof(char) * (len + 1));
	if (sresult == NULL)
		return (NULL);
	k = ft_strlen(s);
	j = 0;
	if (start >= k)
	{
		*sresult = '\0';
		return (sresult);
	}
	while (j < len)
		sresult [j++] = s [start++];
	sresult[j] = '\0';
	return (sresult);
}
