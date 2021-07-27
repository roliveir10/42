#include "libft.h"

t_list	*ft_list_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		new = ft_list_create_elem((*f)(lst->data));
		if (!new)
		{
			ft_list_clear(&new_lst, del);
			return (NULL);
		}
		ft_list_push_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}
