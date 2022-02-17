#include "binary_trees.h"

/**
  * binary_tree_is_full - checks if a binary tree is full
  * @tree: root of the tree
  * Return: 1 if full, 0 otherwise
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_left, is_full_right;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	is_full_left = is_full_right = 0;
	if (tree->left)
		is_full_left = binary_tree_is_full(tree->left);

	if (tree->right)
		is_full_right = binary_tree_is_full(tree->right);

	return (is_full_right * is_full_left);
}
