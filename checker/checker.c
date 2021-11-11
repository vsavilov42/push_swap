#include "../include/push_swap.h"
#include "../include/get_next_line.h"

int main()
{
	t_list	*lst_a;
	t_list	*lst_b;
	int *n;
	int i;

	i = 0;
	lst_a = NULL;
	lst_b = NULL;
	if (argc < 2)
		return (0);
	if (argv[++i][0] == '\0')
		exit(errormsg());
	n = strtonum(stringerror(parse(argv, argc)));
	lst_a = intolist(n, lst_a);
	read_gnl(lst_a, lst_b);
	if (sorted(lst_a) != 1)
		write(1, "KO! Not sorted :c", 17);	
	else
		write(1, "OK! Sorted :D", 13);
	free(n);
	ft_lstclear(&lst_a);
	free(lst_a);
	return (0);
}

void	read_gnl(t_list **lst_a, t_list **lst_b)
{
	char *inst;

	inst = get_nex_line(0);
	while (inst)
	{
		do_instruct(lst_a, lst_b, inst);
		free(inst);
		inst = get_next_line(0);
	}
	free(inst);
}

void	do_instruct(t_list **lst_a, t_list **lst_b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		sa(lst_a, 1);
	else if (!ft_strcmp(inst, "sb\n"))
		sb(lst_b, 1);
	else if (!ft_strcmp(inst, "ss\n"))
		ss(lst_a, lst_b);
	else if (!ft_strcmp(inst, "ra\n"))
		ra(lst_a, 1);
	else if (!ft_strcmp(inst, "rb\n"))
		rb(lst_b, 1);
	else if (!ft_strcmp(inst, "rr\n"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(inst, "rra\n"))
		rra(lst_a, 1);
	else if (!ft_strcmp(inst, "rrb\n"))
		rrb(lst_a, 1);
	else if (!ft_strcmp(inst, "rrr\n"))
		rrr(lst_a, lst_b);
	else if (!ft_strcmp(inst, "pa\n"))
		pa(lst_a, lst_b);
	else if (!ft_strcmp(inst, "pb\n"))
		pb(lst_a, lst_b);
	else
		exit (gnlerror());
}

static int gnlerror(void)
{
	write(1, "KO! Not sorted :c", 17);	
	return (1);
}
