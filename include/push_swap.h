#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_form
{
	int i;
	int j;
	int nwords;
	int *n;
} t_form;

typedef struct s_head
{
	void	*head_a;
} t_head;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
} t_list;

/*t_list->content=(contenido a meter)*/

//array functions

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
int		*strtonum(char *str);
int		ft_atoi(const char *str);
int		*maping(int *n, int nnum);

//list functions

t_list	*intolist(int *n, t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

//sort functions

void	sortlessfive(t_list **lst, int max);
int		isitsorted(t_list **lst);

//move functions

void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst);
void	pb(t_list **lst);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst, t_list **lst_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst);

#endif
