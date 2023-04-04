#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a lintint_t list
 * @head: list
 *
 * Return: nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if ((*head == NULL))
		return;
	while ((*head))
	{
		tmp = (*head);
		free((*head));
		(*head) = tmp;
	}
	(*head) = NULL;
}
