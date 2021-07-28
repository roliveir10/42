#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
