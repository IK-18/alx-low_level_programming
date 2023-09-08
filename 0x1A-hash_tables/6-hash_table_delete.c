#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 *
 * return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp, *head;
	hash_table_t *table;
	unsigned long int i;

	table = ht;
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			head = ht->array[i];
			while (head)
			{
				tmp = head->next;
				free(head->key);
				free(head->value);
				free(head);
				head = tmp;
			}
		}
	}
	free(table->array);
	free(table);
}
