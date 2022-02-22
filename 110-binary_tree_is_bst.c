#include "binary_trees.h"
#include <limits.h>

int is_bst(const binary_tree_t *tree, int, int);

/**
  * binary_tree_is_bst - checks if a tree is a BST
  * @tree: root of the tree
  * Return: 1 if true, 0 otherwise
  */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
  * is_bst - checks if tree is a BST
  * @tree: current node
  * @min: min value allowed below node
  * @max: max value allowed below node
  * Return: 1 if true, 0 otherwise
  */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) *
			is_bst(tree->right, tree->n, max));
}
