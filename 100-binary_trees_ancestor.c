#include "binary_trees.h"

/**
 * level - finds the level of a node in the tree
 * @node: node to return its level in the tree
 * Return: level of the node
 */
int level(binary_tree_t *node)
{
	int lv = 0;

	if (node == NULL)
		return (0);
	while (node->parent != NULL)
	{
		node = node->parent;
		lv++;
	}
	return (lv);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int lv_first, lv_second;

	if (first == NULL || second == NULL)
		return (NULL);
	lv_first = level(first);
	lv_second = level(second);
	while (lv_first > lv_second)
	{
		first = first->parent;
		lv_first--;
	}
	while (lv_second > lv_first)
	{
		second = second->parent;
		lv_second--;
	}
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
