#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	if (tree->right)
	{
		tree->parent = tree->right;
		tree->right = tree->right->left;
		tree->parent->left = tree;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent->parent = NULL;
		tree = tree->parent;
		return (tree);
	}
	return (NULL);
}
