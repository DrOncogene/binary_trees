#include "binary_trees.h"

/**
  * binary_tree_rotate_left - performs left rotation
  * @tree: root node
  * Return: pointer to the new root node
  */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *grandchild_l, *child_r;

	if (!tree)
		return (NULL);

	child_r = tree->right;
	if (child_r)
	{
		child_r->parent = NULL;
		grandchild_l = child_r->left;
		child_r->left = tree;
		tree->parent = child_r;
		tree->right = grandchild_l;
		if (grandchild_l)
			grandchild_l->parent = tree;
	}

	return (child_r);
}
