#include "libft.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data) > 0)
		{
			ft_swap(&tmp->data, &tmp->next->data);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}
