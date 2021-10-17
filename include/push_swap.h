#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

char	*parse(char **arg, int argc);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		errormsg();
char	*stringerror(char *str);
int		countword(char const *s, char c);
char	**ft_split(char const *s, char c);
int		*strsplitatoi(char *str);
int		*checkduples(int *n);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(void *content);

#endif
