#include "binary_trees.h"

bst_t *two_childs(bst_t *node)
{
	bst_t *temp = node;

	while (temp && temp->left != NULL)
		temp = temp->left;
	return (temp);
}

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *succ_p, *succ;

	if (root == NULL)
		return (NULL);
	if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}
	else if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		temp = two_childs(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
