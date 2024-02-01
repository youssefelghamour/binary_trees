#include "binary_trees.h"

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
	if (root->left == NULL)
	{
		temp = root->right;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		temp = root->left;
		free(root);
		return (temp);
	}
	else
	{
		succ_p = root;
		succ = root->right;
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = succ->left;
		}
		if (succ_p != root)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		root->n = succ->n;
		free(succ);
		return (root);
	}
}
