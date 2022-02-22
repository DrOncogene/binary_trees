#include "binary_trees.h"

bst_t *insert_node(bst_t *tree, bst_t *new);

/**
  * bst_insert - inserts a new node into a BST
  * @tree: root of the tree
  * @value: value for the new node
  * Return: pointer to the new node
  */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!tree)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (!(*tree))
	{
		*tree = new;
		return (new);
	}

	return (insert_node(*tree, new));
}

/**
  * insert_node - insert a new node into a BST
  * @tree: the root of the tree
  * @new: the new node
  * Return: pointer to the new node or NULL
  */
bst_t *insert_node(bst_t *tree, bst_t *new)
{
	if (tree->n == new->n)
		return (NULL);

	if (tree->n > new->n)
	{
		if (tree->left)
			return (insert_node(tree->left, new));

		tree->left = new;
		new->parent = tree;
	}

	if (tree->n < new->n)
	{
		if (tree->right)
			return (insert_node(tree->right, new));

		tree->right = new;
		new->parent = tree;
	}

	return (new);
}
