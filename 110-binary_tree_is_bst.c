#include "binary_trees.h"

/**
 * is_bst_util - Utility function for binary_tree_is_bst
 * @tree: Pointer to the root node of the tree
 * @min: Pointer to the minimum node in the tree
 * @max: Pointer to the maximum node in the tree
 * Return: 1 if tree is a BST, otherwise 0
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
    if (!tree)
        return (1);

    if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
        return (0);

    return (is_bst_util(tree->left, min, tree) &&
            is_bst_util(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    return (is_bst_util(tree, NULL, NULL));
}
