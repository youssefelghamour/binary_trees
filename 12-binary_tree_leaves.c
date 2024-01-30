#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to node to count its leaves
 * Return: number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int l_leaves, r_leaves, total;

	if (tree == NULL)
		return (0);
	l_leaves = binary_tree_leaves(tree->left);
	r_leaves = binary_tree_leaves(tree->right);
	total = l_leaves + r_leaves;
	if (tree->left == NULL && tree->right == NULL)
		total++;
	return (total);
}
