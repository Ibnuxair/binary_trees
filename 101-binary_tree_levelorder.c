#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node (with int parameter).
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Create a queue for level-order traversal */
	binary_tree_t **queue = NULL, *current;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;
	/* Enqueue the root node */
	queue = malloc(sizeof(binary_tree_t *) * 1);
	if (queue == NULL)
		return;
	queue[rear] = (binary_tree_t *)tree;
	rear++;
	while (front < rear)
	{
		current = queue[front];
		front++;
		/* Call the provided function for the current node's value */
		func(current->n);
		/* Enqueue the left child if it exists */
		if (current->left != NULL)
		{
			queue = realloc(
				queue, sizeof(binary_tree_t *) * (rear + 1));
			if (queue == NULL)
				return;
			queue[rear] = current->left;
			rear++;
		}
		/* Enqueue the right child if it exists */
		if (current->right != NULL)
		{
			queue = realloc(
				queue, sizeof(binary_tree_t *) * (rear + 1));
			if (queue == NULL)
				return;
			queue[rear] = current->right;
			rear++;
		}
	}
	free(queue);
}
