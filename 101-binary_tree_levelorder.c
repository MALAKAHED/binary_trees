#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    /* Create queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);
    if (!queue)
        return;

    int front = 0, rear = 0;
    const binary_tree_t *current = NULL;

    queue[rear++] = tree;

    while (front < rear)
    {
        current = queue[front++];

        func(current->n);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }

    free(queue);
}
