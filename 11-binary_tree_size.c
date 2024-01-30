#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to root node
 * Return: size of the tree
 */
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
