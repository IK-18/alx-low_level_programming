#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of node to be retrieved
 *
 * Return: the node at index if it exists, else NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (!head)
		return (NULL);
	while (head->prev)
		head = head->prev;
	node = head;
	for (i = 0; i < index; i++)
	{
		if (!node)
			break;
		node = node->next;
	}
	return (node);
}
