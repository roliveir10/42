#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	t_btree	*tmp;
	int		diff;

	tmp = *root;
	diff = 0;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	while (1)
	{
		diff = (*cmpf)(tmp->item, item);
		if (diff < 0 && tmp->right)
			tmp = tmp->right;
		else if (diff >= 0 && tmp->left)
			tmp = tmp->left;
		else
			break ;
	}
	if (diff < 0)
		tmp->right = btree_create_node(item);
	else if (diff >= 0)
		tmp->left = btree_create_node(item);
}
