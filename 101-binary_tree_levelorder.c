#include "binary_trees.h"

/**
  * binary_tree_levelorder - level-order traversal
  * @tree: root of the tree
  * @func: function to apply to each node
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);

	if (tree->left)
	{
		binary_tree_levelorder(tree->left->left, func);
		binary_tree_levelorder(tree->left->right, func);
	}

	if (tree->right)
	{
		binary_tree_levelorder(tree->right->left, func);
		binary_tree_levelorder(tree->right->right, func);
	}
}
