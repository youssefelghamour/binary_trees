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
	l_side = binary_tree_height(tree->left);
	r_side = binary_tree_height(tree->right);
	if (l_side > r_side)
		h = l_side;
	else
		h = r_side;
	return (h + 1);
}

/**
 * print_node - print each node in every level of the tree
 * @tree: pointer to the root of the tree
 * @height: level to print its nodes
 * @func: function pointer to print function
 * Return: nothing
 */
void print_node(const binary_tree_t *tree, int height, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (height == 1)
		func(tree->n);
	else if (height > 1)
	{
		print_node(tree->left, height - 1, func);
		print_node(tree->right, height - 1, func);
	}
}

/**
 * binary_tree_levelorder - travers a binary tree using level-order traversal
 * @tree: pointer to root of the tree
 * @func: function pointer to print function
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, h;

	if (func == NULL || tree == NULL)
		return;
	h = binary_tree_height(tree);
	for (i = 1; i <= h; i++)
		print_node(tree, i, func);
}
