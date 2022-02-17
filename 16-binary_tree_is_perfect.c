#include "binary_trees.h"

size_t height(binary_tree_t *tree);
size_t nodes(binary_tree_t *tree, size_t num_nodes);

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: the root of the tree
  * Return: 1 if perfect, 0 otherwise
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height_l, height_r, nodes_l, nodes_r;

	if (tree == NULL)
		return (0);

	height_r = height(tree->right);
	height_l = height(tree->left);
	nodes_l = nodes(tree->left, 0);
	nodes_r = nodes(tree->right, 0);

	if (height_r == height_l && nodes_l == nodes_r)
		return (1);

	return (0);
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

/**
  * nodes - computes the number of nodes in a binary tree
  * @tree: root of the tree
  * @num_nodes: number of nodes before the current one
  * Return: number of nodes
  */
size_t nodes(binary_tree_t *tree, size_t num_nodes)
{
	if (tree == NULL)
		return (0);

	if (tree->left)
		nodes(tree->left, ++num_nodes);

	if (tree->right)
		nodes(tree->right, ++num_nodes);

	return (num_nodes + 1);
}
