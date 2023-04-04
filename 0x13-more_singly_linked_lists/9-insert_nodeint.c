#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: first node of list
 * @idx: index where new node should be added
 * @n: value of new node
 *
 * Return: address of new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *tmp, *tmp1, *tmp2;
	unsigned int i;

	if (!head || !*head)
		return (NULL);
	tmp = *head;
	for (i = 0; i < idx; i++)
	{
		tmp1 = tmp;
		if (!tmp1)
			return (NULL);
		tmp = tmp1->next;
	}
	tmp2 = tmp1->next;
	if (!tmp2)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = n;
	new->next = tmp2;
	tmp1->next = new;
	return (new);
}
