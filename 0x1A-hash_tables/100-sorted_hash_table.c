#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
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
	new->shead = NULL;
	new->stail = NULL;
	return (new);
}

/**
 * shash_table_set - adds an elemnt to the hash table
 * @ht: hash table
 * @key: key of element
 * @value: value of element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	unsigned long int index;
	char *copy;

	if (!ht || !key || !(*key) || !value)
		return (0);
	copy = strdup(value);
	if (!copy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (!(strcmp(tmp->key, key)))
		{
			free(tmp->value);
			tmp->value = copy;
			return (1);
		}
		tmp = tmp->next;
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
	if (!(ht->shead))
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->next;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (!(tmp->snext))
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: key of element
 *
 * Return: value associated with the element, NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp;
	unsigned long int index;
	char *value = NULL;

	if (!ht || !key || !(*key))
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	tmp = ht->shead;
	if (!tmp || index >= ht->size)
		return (value);
	while (tmp)
	{
		if (!(strcmp(tmp->key, key)))
		{
			value = tmp->value;
			break;
		}
		tmp = tmp->snext;
	}
	return (value);
}

/**
 * shash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;
	node = ht->shead;
	printf("{");
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table
 *
 * return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *head;
	shash_table_t *table = ht;

	if (!ht)
		return;
	head = ht->shead;
	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}
	free(table->array);
	free(table);
}

/**
 * shash_table_print_rev - Prints a hash table in reverse order
 * @ht: hash table
 *
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;
	tmp = ht->stail;
	printf("{");
	while (tmp)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->sprev;
		if (tmp)
			printf(", ");
	}
	printf("}\n");
}
