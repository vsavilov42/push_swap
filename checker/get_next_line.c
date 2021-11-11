/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:15:23 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/11 20:02:10 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sresult;

	if (s == NULL)
		return (NULL);
	sresult = (char *)s;
	while (*sresult != (char)c)
	{
		if (*sresult == '\0')
			return (NULL);
		sresult++;
	}
	return (sresult);
}

char	*get_current_line(char **str)
{
	size_t	i;
	char	*tmp;
	char	*tmpout;

	tmpout = NULL;
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if ((*str)[i] == '\n')
	{
		tmpout = ft_substr(*str, 0, i + 1);
		tmp = ft_strdup(*str + i + 1);
		free(*str);
		*str = tmp;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
		return (tmpout);
	}
	tmpout = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (tmpout);
}

static void	re_read(int fd, char *text, char **stext, ssize_t buff)
{
	char	*tmptext;

	tmptext = NULL;
	while (buff > 0)
	{
		text[buff] = '\0';
		if (*stext == NULL)
			*stext = ft_strdup("");
		tmptext = ft_strjoin(*stext, text);
		free(*stext);
		*stext = tmptext;
		if (ft_strchr(text, '\n'))
			break ;
		buff = read(fd, text, BUFFER_SIZE);
	}
	free (text);
}

char	*get_next_line(int fd)
{
	char		*text;
	static char	*stext = NULL;
	ssize_t		buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (text == NULL)
		return (NULL);
	buff = read(fd, text, BUFFER_SIZE);
	re_read(fd, text, &stext, buff);
	if (buff < 0)
		return (NULL);
	if (!buff && (!stext || !*stext))
		return (NULL);
	return (get_current_line(&stext));
}
