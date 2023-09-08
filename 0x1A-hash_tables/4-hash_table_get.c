#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: key of element
 *
 * Return: value associated with the element, NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *tmp;
	unsigned long int index;
	char *value = NULL;

	if (!ht || !key || !(*key))
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	tmp = ht->array[index];
	if (!tmp)
		return (value);
	while (tmp)
	{
		if (!(strcmp(tmp->key, key)))
		{
			value = tmp->value;
			break;
		}
		tmp = tmp->next;
	}
	return (value);
}
