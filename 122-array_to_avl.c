#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array of 50 values.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array (must be 50).
 * Return: Pointer to root node of created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
avl_t *tree = NULL;
size_t i;

if (!array || size != 50)
return (NULL);

for (i = 0; i < size; i++)
{
if (avl_insert(&tree, array[i]) == NULL)
{

binary_tree_delete(tree);
return (NULL);
}
}

return (tree);
}
