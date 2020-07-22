#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: number of the leaves in a binary tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}


/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left || node->right || !node)
		return (0);
	else
		return (1);
}
