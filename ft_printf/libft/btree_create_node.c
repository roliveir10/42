#include <stdlib.h>
#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (!tree)
		return (NULL);
	tree->left = NULL;
	tree->right = NULL;
	tree->item = item;
	return (tree);
}
