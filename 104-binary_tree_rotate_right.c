#include "binary_trees.h"

/**
  * binary_tree_rotate_right - performs right rotation
  * @tree: root node
  * Return: pointer to the new root node
  */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *root)
{
	binary_tree_t *grandchild_r, *child_l;

	if (!root)
		return (NULL);

	child_l = root->left;
	grandchild_r = child_l->right;
	if (child_l)
	{
		child_l->right = root;
		child_l->parent = root->parent;
		if (root->parent)
		{
			if (root->parent->left == root)
				root->parent->left = child_l;
			else
				root->parent->right = child_l;
		}
		root->parent = child_l;
		root->left = grandchild_r;
		if (grandchild_r)
			grandchild_r->parent = root;
	}

	return (child_l);
}
