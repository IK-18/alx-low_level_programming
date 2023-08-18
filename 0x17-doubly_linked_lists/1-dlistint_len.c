#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: pointer to head of list
 *
 * Return: number iof elements in linked list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	if (!h)
		return (i);
	while (h->prev)
		h = h->prev;
	for (i = 0; h; i++)
		h = h->next;
	return (i);
}
