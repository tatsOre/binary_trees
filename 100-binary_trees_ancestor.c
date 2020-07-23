#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the LCA node of the two given nodes, or NULL on failure
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int depth_fs, depth_sc;

	if (!first || !second)
		return (NULL);

	depth_fs = binary_tree_depth(first);
	depth_sc = binary_tree_depth(second);

	for ( ; depth_fs > depth_sc; depth_fs--)
		first = first->parent;
	for ( ; depth_sc > depth_fs; depth_sc--)
		second = second->parent;
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}

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
