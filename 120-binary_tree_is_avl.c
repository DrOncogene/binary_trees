#include "binary_trees.h"
#include <limits.h>

int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int, int);
size_t height(binary_tree_t *tree);

/**
  * binary_tree_is_avl - checks if a BST is an AVL tree
  * @tree: root of the tree
  * Return: 1 if true, 0 otherwise
  */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_avl_l, is_avl_r, bal;

	if (!tree || !binary_tree_is_bst(tree))
		return (0);

	bal = height(tree->left) - height(tree->right);
	if (!(bal == -1 || bal == 0 || bal == 1))
		return (0);

	is_avl_r = is_avl_l = 1;

	if (tree->left)
		is_avl_l = binary_tree_is_avl(tree->left);
	if (tree->right)
		is_avl_r = binary_tree_is_avl(tree->right);

	return (is_avl_l * is_avl_r);
}

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
