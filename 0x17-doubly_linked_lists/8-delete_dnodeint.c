#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	tmp = *head;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
	}
	for (i = 0; tmp; i++)
	{
		if (i == index)
		{
			if (!i)
			{
				*head = tmp->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
			}
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (-1);
}
