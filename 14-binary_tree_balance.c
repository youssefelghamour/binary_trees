#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of the tree
 *	a negative balance factor means the tree has more nodes on the right
 *	a positive balance factor means the tree has more nodes on the left
 *	a balance factor of 0 indicates that the tree is perfectly balanced.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_left = 0, balance_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		balance_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		balance_right = 1 + binary_tree_height(tree->right);

	return (balance_left - balance_right);
}
