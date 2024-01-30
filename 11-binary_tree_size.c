#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	int l_size, r_size, total;

	if (tree == NULL)
		return (0);
	l_size = binary_tree_size(tree->left);
	r_size = binary_tree_size(tree->right);
	total = l_size + r_size;
	if (tree)
		total++;
	return (total);
}
