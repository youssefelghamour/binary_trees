#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: the root node of the tree to rotate
 *
 *                     (p)
 *                      .
 *                      .
 *            .-------(tree)------.
 *            .                   .
 *       .---(b)---.              .
 * (b->left)     (b->right)
 *
 *
 *
 *                      (p)
 *                       .
 *                       .
 *             .--------(b)------------.
 *             .                       .
 *         (b->left)            .---(tree)---.
 *                          (b->right)       .
 *
 *
 * Return: the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p, *b;

	if (!tree)
		return (NULL);

	p = tree->parent;
	b = tree->left;

	tree->left = b->right;

	if (b->right)
		b->right->parent = tree;

	b->right = tree;
	tree->parent = b;
	b->parent = p;

	if (p)
	{
		if (p->left == tree)
			p->left = b;
		else
			p->right = b;
	}

	return (b);
}
