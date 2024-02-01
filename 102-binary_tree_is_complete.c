#include "binary_trees.h"

/**
 * num_nodes - gets the number of nodes in a tree
 * @tree: root of the tree
 * Return: number of nodes in the tree
 */
int num_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (num_nodes(tree->left) + num_nodes(tree->right) + 1);
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: root of the tree
 * @no_nodes: number of nodes in the tree
 * @idx: index of the node in the array
 * Return: 1 if the tree was complete 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int no_nodes, int idx)
{
	if (tree == NULL)
		return (1);
	if (idx >= no_nodes)
		return (0);
	return (is_complete(tree->left, no_nodes, 2 * idx + 1) &&
		is_complete(tree->right, no_nodes, 2 * idx + 2));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: root of the tree
 * Return: 1 if the tree was complete 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int no_nodes, res;

	if (tree == NULL)
		return (0);
	no_nodes = num_nodes(tree);
	res = is_complete(tree, no_nodes, 0);
	return (res);
}
