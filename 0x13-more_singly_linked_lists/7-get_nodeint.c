#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: first node of list
 * @index: index of node to be found
 *
 * Return: the nth node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp;
	unsigned int i = 0;

	if (!head)
		return (NULL);
	if (index == 0)
		return (head);
	while (i < index)
	{
		tmp = head->next;
		if (!tmp)
			return (NULL);
		head = tmp;
		i++;
	}
	return (tmp);
}
