#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_list_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_list_create_elem(data);
}
