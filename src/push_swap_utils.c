/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:22:10 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/10 18:22:11 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sresult;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sresult = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (sresult == NULL)
		return (NULL);
	ft_strlcpy (sresult, s1, ft_strlen(s1) + 1);
	ft_strlcat (sresult, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (sresult);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while ((src[i]) && (i < dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		while (src[j] && (dst_len + j) < dstsize)
			dst[i++] = src[j++];
	if ((dst_len + j) == dstsize && dst_len < dstsize)
		dst[--i] = '\0';
	else
		dst[i] = '\0';
	return (src_len + dst_len);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	size_t	lstr;

	i = -1;
	lstr = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * lstr + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
