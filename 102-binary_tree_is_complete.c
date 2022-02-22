#include "binary_trees.h"
#include <stdio.h>

size_t height(const binary_tree_t *tree);
int is_complete(const binary_tree_t *, size_t, size_t);
size_t node_count(const binary_tree_t *tree);

/**
  * binary_tree_is_complete - checks if a binary tree is complete
  * @tree: root of the tree
  * Return: 1 if complete, 0 otherwise
  */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (!tree)
		return (0);

	nodes = node_count(tree);

	return (is_complete(tree, 0, nodes));
}

/**
  * is_complete - checks  if a binary tree is complete
  * @tree: root
  * @idx: index of the current node
  * @nodes: total nodes in tree
  * Return: 1 if complete, 0 otherwise
  */
int is_complete(const binary_tree_t *tree, size_t idx, size_t nodes)
{
	if (!tree)
		return (1);

	if (idx >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * idx + 1, nodes) *
			is_complete(tree->right, 2 * idx + 2, nodes));
}

/**
  * node_count - counts the number of nodes in a tree
  * @tree: root of the tree
  * Return: the nodes count
  */
size_t node_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (node_count(tree->left) + 1 + node_count(tree->right));
}
