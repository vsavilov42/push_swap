/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:50:37 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/15 11:53:01 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_form
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	nwords;
	int	*n;
}	t_form;

typedef struct s_chunks
{
	int	tpa;
	int	num;
	int	check;
	int	chunksize;
	int	halfchunk;
}	t_chunk;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

/*t_list->content=(contenido a meter)*/

//array functions

char	*parse(char **arg, int argc);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		errormsg(void);
char	*stringerror(char *str);
int		countword(char const *s, char c);
char	**ft_split(char const *s, char c);
int		*strtonum(char *str);
int		ft_atoi(const char *str);
int		*maping(int *n, int nnum);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//list functions

void	list(t_list **lst_a, t_list **lst_b);

t_list	*intolist(int *n, t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

//sort functions

int		fix_troll(t_list **lst_a);
void	sort_two(t_list **lst);
int		*two_littles(t_list	**lst);
void	sort_three(t_list **lst);
void	sort_four(t_list **lst_a, t_list **lst_b);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	sort_less_ten(t_list **lst_a, t_list **lst_b);
void	sort_chunks(t_list **lst_a, t_list **lst_b);
void	sort_big_chunks(t_list **lst_a, t_list **lst_b, int m);
void	sort_big_chunks_b_to_a(t_list **lst_a, t_list **lst_b);
void	sort_chunks_a_to_b(t_list **lst_a, t_list **lst_b, int max);
void	sort_chunks_rotate_list_a(t_list **lst_a, int max, int tpa, int chunk);
void	sort_chunks_b_to_a(t_list **lst_a, t_list **lst_b);
void	sort_list(t_list **lst_a, t_list **lst_b, int max);
int		sorted(t_list **lst);

//junk chunks functions

int		b_to_a_rb(t_list **lst_a, t_list **lst_b, int num, int check);
int		b_to_a_rrb(t_list **lst_a, t_list **lst_b, int num, int check);
int		where_is_num(t_list **lst, int num, int tpa);

//move functions

void	sa(t_list **lst, int check);
void	sb(t_list **lst, int check);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst_a, t_list **lst_b, int check);
void	pb(t_list **lst_a, t_list **lst_b, int check);
void	ra(t_list **lst, int check);
void	rb(t_list **lst, int check);
void	rr(t_list **lst, t_list **lst_b);
void	rra(t_list **lst, int check);
void	rrb(t_list **lst, int check);
void	rrr(t_list **lst_a, t_list **lst_b);

//bonus functions

void	read_gnl(t_list **lst_a, t_list **lst_b);
void	do_instruct(t_list **lst_a, t_list **lst_b, char *inst);

#endif
