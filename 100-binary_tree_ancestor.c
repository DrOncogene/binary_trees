#include "binary_trees.h"

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: first node
  * @second: second node
  * Return: pointer to their ancestor or NULL
  */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, 
										const binary_tree_t *second){
	if (!first || !second)
		return (NULL);

	if (first->parent == second)
		return (second);
	if (second->parent == first)
		return (first);

	if (first->parent == second->parent)
		return (first->parent);


}
