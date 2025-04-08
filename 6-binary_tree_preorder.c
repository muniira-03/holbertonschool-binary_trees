#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description:
 *   - Pre-order traversal visits the root node first, then the left subtree,
 *     and finally the right subtree.
 *   - If `tree` or `func` is NULL, the function does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);
}
