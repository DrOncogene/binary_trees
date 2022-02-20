#include "binary_trees.h"

size_t height(binary_tree_t *tree);

/**
  * binary_tree_balance - measures the balance factor of a binary tree
  * @tree: the root node
  * Return: the balance factor
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height, balance;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	balance = left_height - right_height;

	return (balance);
}

/**
  * height - calculate the height of a tree
  * @tree: root of the tree
  * Return: the height
  */
size_t height(binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = right_height = 1;
	if (tree->left)
		left_height = height(tree->left) + 1;
	if (tree->right)
		right_height = height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);

	return (right_height);
}
