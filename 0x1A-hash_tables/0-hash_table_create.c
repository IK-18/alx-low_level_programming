#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;
	unsigned long int i;

	new = malloc(sizeof(hash_table_t));
	if (!new)
		return (NULL);
	new->size = size;
	new->array = calloc(new->size, sizeof(hash_node_t));
	if (!(new->array))
		return (NULL);
	for (i = 0; i < new->size; i++)
		new->array[i] = NULL;
	return (new);
}
