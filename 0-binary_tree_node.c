#include "binary_trees.h"

/**
 * binary_tree_node - This is the function that creates a binary tree node
 * @parent: This is the pointer to the parent node to be created
 * @value: This is the value to be inserted
 *
 * Return: The function must return a pointer to the new node,
 * or NULL on failure
 *
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;

	return (new_node);
}
