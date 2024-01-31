#include "binary_trees.h"

/**
 * LCA - finds the lowest common ancestor of two nodes
 * @root: root node of the tree
 * @node1: first node
 * @node2: second node
 * Return: lowest common ancestor
 */
binary_tree_t *LCA(binary_tree_t *root,
		   binary_tree_t *node1, binary_tree_t *node2)
{
	binary_tree_t *l_lca, *r_lca;

	if (root == node1 || root == node2)
		return (root);
	l_lca = LCA(root->left, node1, node2);
	r_lca = LCA(root->right, node1, node2);
	if (l_lca == NULL && r_lca == NULL)
		return (NULL);
	if (l_lca && r_lca)
		return (root);
	if (l_lca == NULL)
		return (r_lca);
	else
		return (l_lca);
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
	binary_tree_t *root = (binary_tree_t *)first, *lca;

	if (first == NULL || second == NULL)
		return (NULL);
	while (root->parent != NULL)
		root = root->parent;
	lca = LCA(root, (binary_tree_t *)first, (binary_tree_t *)second);
	return (lca);
}

