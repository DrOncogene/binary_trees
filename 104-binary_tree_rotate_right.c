#include "binary_trees.h"

/**
  * binary_tree_rotate_right - performs right rotation
  * @tree: root node
  * Return: pointer to the new root node
  */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *grandchild_r, *child_l;

	if (!tree)
		return (NULL);

	child_l = tree->left;
	if (child_l)
	{
		child_l->parent = NULL;
		grandchild_r = child_l->right;
		child_l->right = tree;
		tree->parent = child_l;
		tree->left = grandchild_r;
		if (grandchild_r)
			grandchild_r->parent = tree;
	}

	return (child_l);
}
