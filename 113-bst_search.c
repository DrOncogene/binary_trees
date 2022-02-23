#include "binary_trees.h"

/**
  * bst_search - searches for a value in a BST
  * @tree: root of the tree
  * @value: value to search for
  * Return: pointer to the found node
  */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found_l, *found_r;

	if (!tree)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	found_l = found_r = NULL;
	if (tree->left)
		found_l = bst_search(tree->left, value);
	if (tree->right)
		found_r = bst_search(tree->right, value);

	if (!found_l && !found_r)
		return (NULL);
	if (found_l)
		return (found_l);
	if (found_r)
		return (found_r);

	return (NULL);
}
