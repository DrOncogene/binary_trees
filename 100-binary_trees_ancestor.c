#include "binary_trees.h"

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: first node
  * @second: second node
  * Return: pointer to their ancestor or NULL
  */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second){
	binary_tree_t *ancestor_first, *ancestor_second;

	if (!first || !second)
		return (NULL);

	if (!first->parent)
		return ((binary_tree_t *)first);
	if (!second->parent)
		return ((binary_tree_t *)second);

	ancestor_first = (binary_tree_t *)first;
	while (ancestor_first)
	{
		ancestor_second = (binary_tree_t *)second;
		while (ancestor_second)
		{
			if (ancestor_first == ancestor_second)
				return (ancestor_first);
			ancestor_second = ancestor_second->parent;
		}

		ancestor_first = ancestor_first->parent;
	}

	return (NULL);
}
