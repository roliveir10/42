#include <stdlib.h>
#include "libft.h"

void	ft_list_clear(t_list **lst, void (*del)(void *))
{
	if (*lst && (*lst)->next)
		ft_list_clear(&(*lst)->next, del);
	if (*lst)
	{
		ft_list_del_one(*lst, del);
		*lst = NULL;
	}
}
