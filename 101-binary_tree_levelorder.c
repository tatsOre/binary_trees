#include "binary_trees.h"

/**
 * print_levelorder - Goes through a BT using level-order traversal - Aux Func
 * @tree: pointer to the root node of the tree to traverse
 * @f: pointer to a function to call for each node
 * @lvl: level node to print
 * Return: nothing
 */
void print_levelorder(const binary_tree_t *tree, void (*f)(int), size_t lvl)
{
	if (!tree)
		return;
	if (lvl == 0)
		f(tree->n);
	else if (lvl > 0)
	{
		print_levelorder(tree->left, f, lvl - 1);
		print_levelorder(tree->right, f, lvl - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a BT using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * The value in the node must be passed as a parameter to this function
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height(tree), level = 0;

	if (!tree || !func)
		return;

	while (height >= level)
	{
		print_levelorder(tree, func, level);
		level++;
	}
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
