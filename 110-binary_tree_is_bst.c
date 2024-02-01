#include "binary_trees.h"
#include <limits.h>

/**
 * bst - helper function to checks if a binary tree is a valid BST
 *
 * @tree: the root node of the tree to check
 * @min: The minimum allowed value for nodes in the subtree
 * @max: The minimum allowed value for nodes in the subtree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if ((tree->n <= min) || (tree->n >= max))
		return (0);

	return (bst(tree->left, min, tree->n) && bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	return (bst(tree, INT_MIN, INT_MAX));
}
