#include "hash_tables.h"

/**
 * key_index - gives the index of the key
 * @key: the key to be stored in the hash table
 * @size: size of the array of the hash table
 *
 * Return: the index in which the key is stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
