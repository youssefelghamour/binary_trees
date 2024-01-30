#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root node
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int l_side, r_side, h;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	l_side = binary_tree_height(tree->left);
	r_side = binary_tree_height(tree->right);
	if (l_side > r_side)
		h = l_side;
	else
		h = r_side;
	return (h + 1);
}

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

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);


	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (!binary_tree_balance(tree) && binary_tree_is_full(tree));
}
