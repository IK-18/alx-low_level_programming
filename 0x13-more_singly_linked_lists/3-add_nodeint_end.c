#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: first node in list
 * @n: vslue of new node
 *
 * Return: address of new element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *tmp;

	tmp = malloc(sizeof(listint_t));
	if (!tmp)
		return (NULL);
	tmp->n = n;
	tmp->next = NULL;
	if ((*head) == NULL)
	{
		(*head) = tmp;
		return (tmp);
	}
	while ((*head)->next)
		(*head) = (*head)->next;
	(*head)->next = tmp;
	return (tmp);
}
