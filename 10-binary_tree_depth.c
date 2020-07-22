#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: depth of the node, or 0 if node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	for ( ; tree->parent ; tree = tree->parent, depth++)
		;
	return (depth);
}
