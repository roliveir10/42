#include "libft.h"

void	ft_list_iter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->data);
		lst = lst->next;
	}
}
