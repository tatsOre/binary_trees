#include "binary_trees.h"

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
