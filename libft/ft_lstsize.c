#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (1 + ft_lstsize(lst->next));
	return (0);
}
