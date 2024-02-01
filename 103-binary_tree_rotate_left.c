#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: the root node of the tree to rotate
 *
 *                      (p)
 *                       .
 *                       .
 *             .-------(tree)------.
 *             .                   .
 *             .              .---(b)---.
 *                      (b->left)     (b->right)
 *
 *
 *
 *                      (p)
 *                       .
 *                       .
 *             .--------(b)------------.
 *             .                       .
 *      .---(tree)---.            (b->right)
 *      .         (b->left)
 *
 * Return: the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *p, *b;

	if (!tree)
		return (NULL);

	p = tree->parent;
	b = tree->right;

	tree->right = b->left;

	if (b->left)
		b->left->parent = tree;

	b->left = tree;
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
