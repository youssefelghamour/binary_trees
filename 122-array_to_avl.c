#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to represented in the AVL tree
 * @size: size of the array
 * Return: root node of the AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	int i;
	avl_t *tree = NULL;

	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}
	return (tree);
}
