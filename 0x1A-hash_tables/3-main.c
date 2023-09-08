#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    unsigned long int index1, index2;
    hash_node_t *current1, *current2;

    ht = hash_table_create(1024);
    hash_table_set(ht, "hetairas", "cool");
    hash_table_set(ht, "heliotropes", "helio");
    hash_table_set(ht, "mentioner", "mention");
    hash_table_set(ht, "neurospora", "neuro");
    index1 = key_index((unsigned char *)"mentioner", ht->size);
    index2 = key_index((unsigned char *)"heliotropes", ht->size);
    current1 = ht->array[index1];
    current2 = ht->array[index2];
    printf("%s\n", current1->value);
    printf("%s\n", current2->value);
    if (current1->next)
	    printf("%s\n", current1->next->value);
    if (current2->next)
	    printf("%s\n", current2->next->value);
    return (EXIT_SUCCESS);
}
