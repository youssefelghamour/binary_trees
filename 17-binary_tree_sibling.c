#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: the node to find the sibling for
 *
 * Return: the sibling node; NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node && node->parent->right)
		return (node->parent->right);

	if (node->parent->right == node && node->parent->left)
		return (node->parent->left);

	return (NULL);
}
