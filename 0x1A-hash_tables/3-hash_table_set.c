#include "hash_tables.h"

/**
 * hash_table_set - adds an elemnt to the hash table
 * @ht: hash table
 * @key: key of element
 * @value: value of element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	unsigned long int index;
	char *copy;

	if (!ht || !key || !(*key) || !value)
		return (0);
	copy = strdup(value);
	if (!copy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index])
	{
		if (!(strcmp(ht->array[index]->key, key)))
		{
			free(ht->array[index]->value);
			ht->array[index]->value = copy;
			return (1);
		}
	}
	new = malloc(sizeof(hash_node_t));
	new->key = strdup(key);
	if (!new || !(new->key))
	{
		free(copy);
		free(new);
		return (0);
	}
	new->value = copy;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
