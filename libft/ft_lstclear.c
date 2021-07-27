#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst && (*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	if (*lst)
	{
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
