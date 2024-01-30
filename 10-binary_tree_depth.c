#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to return its depth
 * Return: depth of a node in the tree
 */
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
