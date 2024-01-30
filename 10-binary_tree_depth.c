#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);
	depth = binary_tree_depth(tree->parent);
	if (tree->parent)
		depth++;
	return (depth);
}
