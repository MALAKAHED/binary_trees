#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int found_null = 0;
    const binary_tree_t *temp;

    if (!tree)
        return (0);

    temp = tree;
    while (temp)
    {
        if (temp->left && !found_null)
            temp = temp->left;
        else if (!temp->left && found_null && temp->right)
            return (0);
        else if (!temp->left && !found_null)
            found_null = 1;
        else if (temp->left && found_null)
            return (0);

        if (temp->right && !found_null)
            temp = temp->right;
        else if (!temp->right && found_null)
            found_null = 1;
        else if (!temp->right && !found_null)
            found_null = 1;
        else if (temp->right && found_null)
            return (0);
    }

    return (1);
}
