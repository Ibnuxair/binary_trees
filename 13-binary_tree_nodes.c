#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: The number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes = 0, right_nodes = 0;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (
		(left_nodes + right_nodes) +
		(tree->left || tree->right ? 1 : 0)
		);
}
