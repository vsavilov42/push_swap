/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:53:40 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 11:53:40 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**singleword(char const *s, char c, char **sresult)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		len = 0;
		while (*s != c && *s && ++s)
			len++;
		sresult[i] = malloc(len + 1);
		if (sresult[i] == NULL)
		{
			while (--i >= 0)
				free(sresult[i]);
			free(sresult);
			return (NULL);
		}
		ft_strlcpy(sresult[i++], s - len, len + 1);
		while (*s == c && *s)
			s++;
	}
	sresult[i] = NULL;
	return (sresult);
}

int	countword(char const *s, char c)
{
	int	nwords;

	nwords = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		nwords++;
		while (*s == c && *s)
			s++;
	}
	return (nwords);
}

char	**ft_split(char const *s, char c)
{
	size_t	cwords;
	char	**sresult;

	if (s == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	cwords = (countword(s, c));
	sresult = (char **)malloc(sizeof(char *) * (cwords + 1));
	if (sresult == NULL)
		return (NULL);
	sresult = singleword(s, c, sresult);
	return (sresult);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
