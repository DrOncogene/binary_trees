#include "binary_trees.h"

void current_level(const binary_tree_t *, size_t, void(*func)(int));
size_t height(const binary_tree_t *);

/**
  * binary_tree_levelorder - level-order traversal
  * @tree: root  of the tree
  * @func: function to apply to each node
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height, i;

	if (!tree || !func)
		return;

	tree_height = height(tree);
	for (i = 0; i <= tree_height; i++)
		current_level(tree, i, func);
}

/**
  * current_level - runs through the current level
  * @root: tree root
  * @level: the current level to be checked
  * @func: function to run on the node values
  * Return: nothing
  */
void current_level(const binary_tree_t *root, size_t level, void(*func)(int))
{
	if (!root)
		return;

	if (level == 0)
		func(root->n);
	else if (level > 0)
	{
		current_level(root->left, level - 1, func);
		current_level(root->right, level - 1, func);
	}
}

/**
 * height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = height(tree->left) + 1;
	if (tree->right != NULL)
		right_height = height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);

	return (right_height);
}
