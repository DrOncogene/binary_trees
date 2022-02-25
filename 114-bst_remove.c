#include "binary_trees.h"
#include <stdio.h>

bst_t *find_min(bst_t *node);

/**
  * bst_remove - remove a node from a BST
  * @root: root of the node
  * @value: value of the node to remove
  * Return: pointer to the new root
  */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor;

	if (!root)
		return (root);

	if (root->n < value)
		root->right = bst_remove(root->right, value);
	else if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
	{
		if (!root->left)
		{
			successor = root->right;
			free(root);
			return (successor);
		}
		if (!root->right)
		{
			successor = root->left;
			free(root);
			return (successor);
		}

		successor = find_min(root->right);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}

/**
  * find_min - finds the minimum value in a subtree
  * @node: root of the subtree
  * Return: the minimum
  */
bst_t *find_min(bst_t *node)
{
	bst_t *current;

	current = node;
	while (current && current->left)
		current = current->left;

	return (current);
}
