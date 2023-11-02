#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 if not, or if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int isLastLevel = 0;
	binary_tree_t *queue[10000], *current;
	size_t front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (rear > front)
	{
		current = queue[front];
		front++;

		if (current == NULL)
			isLastLevel = 1;
		else
		{
			if (isLastLevel)
				return (0);

			queue[rear] = current->left;
			rear++;
			queue[rear] = current->right;
			rear++;
		}
	}

	return (1);
}
