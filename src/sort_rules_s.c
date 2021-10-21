#include "../include/push_swap.h"

void	*sa(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return (NULL);

	printf("item 1 %p\n", lst);
	printf("item 2 %p\n", (*lst)->next);
	printf("item 3 %p\n", (*lst)->next->next);

	// lst >			es el elemento uno
	// lst->next >		elemento dos
	// lst->next->next	elemento tres

	// el elemento 1 apunta al 2 y el 2 al 3

	// debería quedar como:
	// el elemento 1 apunte al 3 y el 2 al 1

	tmp = *lst;	

	printf("item 1 %p\n", lst);
	printf("item 2 %p\n", (*lst)->next);
	printf("item 3 %p\n", (*lst)->next->next);
	return (lst);
}
