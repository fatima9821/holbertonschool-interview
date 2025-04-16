#include "binary_trees.h"
#include <stdlib.h>

/**
 * level_order_insert - Finds the first free position using level-order
 * @tree: Pointer to root node
 * @node: New node to insert
 * Return: Parent node where we inserted
 */
static heap_t *level_order_insert(heap_t *tree, heap_t *node)
{
	heap_t *queue[1024], *parent = NULL;
	int front = 0, rear = 0;

	queue[rear++] = tree;

	while (front < rear)
	{
		parent = queue[front++];

		if (!parent->left)
		{
			parent->left = node;
			node->parent = parent;
			return (parent);
		}
		else
			queue[rear++] = parent->left;

		if (!parent->right)
		{
			parent->right = node;
			node->parent = parent;
			return (parent);
		}
		else
			queue[rear++] = parent->right;
	}

	return (NULL);
}

/**
 * swap_up - Moves the inserted node up to maintain heap property
 * @node: Pointer to the node to adjust
 * Return: Pointer to node after swap (new position)
 */
static heap_t *swap_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	if (!root)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*root)
	{
		*root = node;
		return (node);
	}

	level_order_insert(*root, node);
	return (swap_up(node));
}
