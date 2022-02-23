#include "binary_trees.h"

/**
  * array_to_bst - converts an array to a BST
  * @array: the array
  * @size: size of the array
  * Return: pointer to the root of the new BST
  */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (!array || !size)
		return (NULL);

	root = (bst_t *)binary_tree_node(NULL, array[0]);
	if (!root)
		return (NULL);

	for (i = 1; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
