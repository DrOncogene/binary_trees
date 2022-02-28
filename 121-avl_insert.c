#include "binary_trees.h"

avl_t *insert_node(avl_t *tree, int value);
avl_t *rotate(avl_t *tree);

/**
  * avl_insert - inserts a new node into a AVL tree
  * @tree: the root of the tree
  * @value: value of the new node
  * Return: pointer to the new node
  */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *new_root;

	new = insert_node(*tree, value);
	if (!new)
		return (NULL);
	if (!(*tree))
		*tree = new;

	new_root = rotate(new);
	if (!new_root->parent)
		*tree = new_root;

	return (new);
}

/**
  * rotate - performs the appropriate rotations on a tree
  * @new: the new node added to the tree
  * Return: pointer to the new root of the rotated subtree or NULL
  */
avl_t *rotate(avl_t *new)
{
	avl_t *parent;
	int bal;

	if (!new)
		return (NULL);

	parent = new->parent;
	while (parent)
	{
		bal = binary_tree_balance(parent);
		if (bal == -1 || bal == 0 || bal == 1)
		{
			parent = parent->parent;
			continue;
		}
		if (bal < -1 && new->n > parent->right->n)
			return (binary_tree_rotate_left(parent));
		if (bal > 1 && new->n < parent->left->n)
			return (binary_tree_rotate_right(parent));

		if (bal < -1 && new->n < parent->right->n)
		{
			parent->right = binary_tree_rotate_right(parent->right);
			return (binary_tree_rotate_left(parent));
		}
		if (bal > 1 && new->n > parent->left->n)
		{
			parent->left = binary_tree_rotate_left(parent->left);
			return (binary_tree_rotate_right(parent));
		}
	}

	return (new);
}

/**
  * insert_node - insert a new node into a BST
  * @tree: the root of the tree
  * @value: value to store in the new node
  * Return: pointer to the new node or NULL
  */
avl_t *insert_node(avl_t *tree, int value)
{
	avl_t *new;

	if (!tree)
	{
		new = binary_tree_node(tree, value);
		return (new);
	}

	if (tree->n == value)
		return (NULL);

	if (tree->n > value)
	{
		if (tree->left)
			return (insert_node(tree->left, value));
		new = (avl_t *)binary_tree_node(NULL, value);
		tree->left = new;
		new->parent = tree;
	}

	if (tree->n < value)
	{
		if (tree->right)
			return (insert_node(tree->right, value));
		new = (avl_t *)binary_tree_node(NULL, value);
		tree->right = new;
		new->parent = tree;
	}

	return (new);
}
