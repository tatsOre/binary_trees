#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 | 0, or 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size = (int)binary_tree_size(tree);
/* A perfect binary tree of height 'h' has 2exp(h + 1) - 1 node. */
	return ((1 << (height + 1)) - 1 == size ? 1 : 0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (left >= right ? left + 1 : right + 1);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);
	return (left + right + 1);
}
