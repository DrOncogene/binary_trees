#include "binary_trees.h"

/**
  * binary_tree_uncle - finds the uncle of a given node
  * @node: the node
  * Return: pointer to the uncle or NULL
  */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent, *parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grandparent = node->parent->parent;
	parent = node->parent;

	if (grandparent->left == parent)
		return (grandparent->right);

	if (grandparent->right == parent)
		return (grandparent->left);

	return (NULL);
}
