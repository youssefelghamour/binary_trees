#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *				If parent already has a right-child, the new node must take its place,
 *				and the old right-child must be set as the right-child of the new node.
 *
 * @parent: the parent node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return:  the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (parent->right != NULL)
	{
		temp = parent->right;
		parent->right = new_node;
		new_node->parent = parent;
		new_node->right = temp;
	}
	else
	{
		new_node->parent = parent;
		parent->right = new_node;
	}

	return (new_node);
}
