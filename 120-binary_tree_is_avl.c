#include "binary_trees.h"
#include <limits.h>

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

int is_avl(const binary_tree_t *root, int min, int max)
{
	int l_side, r_side;

	if (root == NULL)
		return (1);
	if (root->n > max || root->n < min)
		return (0);
	l_side = binary_tree_height(root->left);
	r_side = binary_tree_height(root->right);
	if (abs(l_side - r_side) > 1)
		return (0);
	return (is_avl(root->left, min, root->n - 1) &&
		is_avl(root->right, root->n + 1, max));
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
