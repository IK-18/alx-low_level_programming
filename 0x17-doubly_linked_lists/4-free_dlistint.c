#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t
 * @head: pointer to head of list
 *
 * Return: Nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head)
	{
		while (head->prev)
			head = head->prev;
	}
	while ((tmp = head))
	{
		head = head->next;
		free(tmp);
	}
}
