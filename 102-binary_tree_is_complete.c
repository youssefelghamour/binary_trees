#include "binary_trees.h"

int num_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (num_nodes(tree->left) + num_nodes(tree->right) + 1);
}

int is_complete(const binary_tree_t *tree, int no_nodes, int idx)
{
	if (tree == NULL)
		return (1);
	if (idx >= no_nodes)
		return (0);
	return (is_complete(tree->left, no_nodes, 2 * idx + 1) &&
		is_complete(tree->right, no_nodes, 2 * idx + 2));
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int no_nodes, res;

	if (tree == NULL)
		return (0);
	no_nodes = num_nodes(tree);
	res = is_complete(tree, no_nodes, 0);
	return (res);
}
