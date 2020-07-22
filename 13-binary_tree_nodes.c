#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of the leaves in a binary tree, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || binary_tree_is_leaf(tree))
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	return (left + right + 1);
}


/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
