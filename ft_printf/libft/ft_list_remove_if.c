#include <stdlib.h>
#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*first;
	t_list	*tmp;

	first = *begin_list;
	while (first && (*cmp)(first->data, data_ref) == 0)
	{
		*begin_list = first->next;
		(*free_fct)(first->data);
		free(first);
		first = *begin_list;
	}
	while (first && first->next)
	{
		if ((*cmp)(first->next->data, data_ref) == 0)
		{
			(*free_fct)(first->next->data);
			if (first->next->next)
				tmp = first->next->next;
			else
				tmp = NULL;
			free(first->next);
			first->next = tmp;
		}
		first = first->next;
	}
}
