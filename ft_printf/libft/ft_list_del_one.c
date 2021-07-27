#include <stdlib.h>
#include "libft.h"

void	ft_list_del_one(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->data);
		free(lst);
	}
}
