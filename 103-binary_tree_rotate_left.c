#include "binary_trees.h"

/**
  * binary_tree_rotate_left - performs left rotation
  * @tree: root node
  * Return: pointer to the new root node
  */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *root)
{
	binary_tree_t *grandchild_l, *child_r;

	if (!root)
		return (NULL);

	child_r = root->right;
	grandchild_l = child_r->left;
	if (child_r)
	{
		child_r->left = root;
		child_r->parent = root->parent;
		if (root->parent)
		{
			if (root->parent->left == root)
				root->parent->left = child_r;
			else
				root->parent->right = child_r;
		}
		root->parent = child_r;
		root->right = grandchild_l;
		if (grandchild_l)
			grandchild_l->parent = root;
	}

	return (child_r);
}
