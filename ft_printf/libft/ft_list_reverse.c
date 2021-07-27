#include "libft.h"

void	ft_list_reverse(t_list *begin_list)
{
	unsigned int	size;
	t_list			*last;
	t_list			*first;
	unsigned int	i;

	i = 0;
	size = ft_list_size(begin_list);
	first = begin_list;
	while (i < size / 2)
	{
		last = ft_list_at(begin_list, size - 1 - i);
		ft_swap(&last->data, &first->data);
		first = first->next;
		i++;
	}
}
