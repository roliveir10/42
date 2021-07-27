#include "libft.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&lst, strs[i]);
		i++;
	}
	return (lst);
}
