#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: the root node of the tree to count the number of nodes
 *
 * Return: the number of tree nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nb_tree_nodes = 0;

	if (!tree)
		return (0);

	if (tree->right || tree->left)
		nb_tree_nodes++;

	nb_tree_nodes += binary_tree_nodes(tree->left);
	nb_tree_nodes += binary_tree_nodes(tree->right);

	return (nb_tree_nodes);
}
