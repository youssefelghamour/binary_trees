#include "binary_trees.h"

/**
 * avl_ins - AVL insertion according to value
 * @tree: root node
 * @p: parent node
 * @temp: pointer for insertion in left or right subtree
 * @n: value to be inserted in AVL tree
 * Return: pointer to the created node
 */
avl_t *avl_ins(avl_t **tree, avl_t *p, avl_t **temp, int n)
{
	int balance;

	if (*tree == NULL)
		return (*temp = binary_tree_node(p, n));
	if ((*tree)->n > n)
	{
		(*tree)->left = avl_ins(&(*tree)->left, *tree, temp, n);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < n)
	{
		(*tree)->right = avl_ins(&(*tree)->right, *tree, temp, n);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	balance = binary_tree_balance(*tree);
	if (balance > 1 && (*tree)->left->n > n)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance > 1 && (*tree)->left->n < n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < n)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: root node
 * @value: value to be inserted
 * Return: pointer to created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *temp = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_ins(tree, *tree, &temp, value);
	return (temp);
}
