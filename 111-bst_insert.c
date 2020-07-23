#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 *         If tree is NULL, the created node must become the root node.
 *         If the value is already present in the tree, it must be ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root = *tree;

	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(*tree, value);
		return (*tree);
	}
	while (root && value != root->n)
	{
		if (value < root->n)
		{
			if (!root->left)
			{
				root->left = (bst_t *)binary_tree_node(root, value);
				return (root->left);
			}
			root = root->left;
		}
		else if (value > root->n)
		{
			if (!root->right)
			{
				root->right = (bst_t *)binary_tree_node(root, value);
				return (root->right);
			}
			root = root->right;
		}
	}
	return (NULL);
}
