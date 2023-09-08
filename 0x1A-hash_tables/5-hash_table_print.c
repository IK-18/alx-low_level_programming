#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int comma = 0;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			node = ht->array[i];
			if (comma)
				printf(", ");
			while (node)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node)
					printf(", ");
			}
			comma = 1;
		}
	}
	printf("}\n");
}
