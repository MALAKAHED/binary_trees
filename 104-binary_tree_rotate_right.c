#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root, *temp;

    if (!tree || !tree->left)
        return (NULL);

    new_root = tree->left;
    if (new_root->right)
    {
        temp = new_root->right;
        temp->parent = tree;
    }
    else
        temp = NULL;

    new_root->right = tree;
    tree->parent = new_root;
    tree->left = temp;

    new_root->parent = NULL;
    return (new_root);
}
