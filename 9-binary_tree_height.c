#include "binary_trees.h"
#include <stdlib.h>

int max(int num1, int num2);

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;

	return (max(left_height, right_height));
}

int max(int num1, int num2) {
	if (num1 > num2) 
		return (num1);
	return (num2);
}
