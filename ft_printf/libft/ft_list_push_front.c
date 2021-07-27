#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_list_create_elem(data);
	if (*begin_list)
		first->next = *begin_list;
	*begin_list = first;
}
