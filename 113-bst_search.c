#include "binary_trees.h"

/**
  * bst_search - searches for a value in a BST
  * @tree: root of the tree
  * @value: value to search for
  * Return: pointer to the found node
  */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (!tree)
		return (NULL);

	found = NULL;
	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n < value)
		found = bst_search(tree->right, value);
	if (tree->n > value)
		found = bst_search(tree->left, value);

	return (found);
}
