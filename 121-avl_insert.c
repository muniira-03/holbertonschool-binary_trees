#include "binary_trees.h"

/**
 * height - Measures height of a binary tree.
 * @tree: Pointer to root node to measure.
 * Return: Tree height, 0 if NULL.
 */
int height(const binary_tree_t *tree)
{
return (tree ? 1 + MAX(height(tree->left), height(tree->right)) : 0);
}

/**
 * balance_factor - Calculates node's balance factor.
 * @tree: Pointer to node to measure.
 * Return: Balance factor (left height - right height).
 */
int balance_factor(const binary_tree_t *tree)
{
return (tree ? height(tree->left) - height(tree->right) : 0);
}

/**
 * rotate_left - Performs left rotation.
 * @x: Pointer to root node to rotate.
 * Return: New root after rotation.
 */
avl_t *rotate_left(avl_t *x)
{
avl_t *y = x->right;

x->right = y->left;
if (y->left)
y->left->parent = x;
y->left = x;
y->parent = x->parent;
x->parent = y;
return (y);
}

/**
 * rotate_right - Performs right rotation.
 * @y: Pointer to root node to rotate.
 * Return: New root after rotation.
 */
avl_t *rotate_right(avl_t *y)
{
avl_t *x = y->left;

y->left = x->right;
if (x->right)
x->right->parent = y;
x->right = y;
x->parent = y->parent;
y->parent = x;
return (x);
}

/**
 * avl_insert - Inserts value into AVL tree.
 * @tree: Double pointer to root node.
 * @value: Value to insert.
 * Return: Pointer to new node, NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
int bf;

if (!tree)
return (NULL);
if (!*tree)
return (*tree = binary_tree_node(NULL, value));

if (value < (*tree)->n)
{
(*tree)->left = avl_insert(&(*tree)->left, value);
(*tree)->left->parent = *tree;
}
else if (value > (*tree)->n)
{
(*tree)->right = avl_insert(&(*tree)->right, value);
(*tree)->right->parent = *tree;
}
else
return (*tree);

bf = balance_factor(*tree);
if (bf > 1 && value < (*tree)->left->n)
return (rotate_right(*tree));
if (bf < -1 && value > (*tree)->right->n)
return (rotate_left(*tree));
if (bf > 1 && value > (*tree)->left->n)
{
(*tree)->left = rotate_left((*tree)->left);
return (rotate_right(*tree));
}
if (bf < -1 && value < (*tree)->right->n)
{
(*tree)->right = rotate_right((*tree)->right);
return (rotate_left(*tree));
}
return (*tree);
}
