#include "libft.h"

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + ft_max(btree_level_count(root->left),
			btree_level_count(root->right)));
}
