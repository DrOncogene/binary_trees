#include "binary_trees.h"

/**
  * binary_tree_sibling - finds the sibling of a given node
  * @node: the node
  * Return: pointer to the sibling or NULL
  */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node->parent || !node)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}