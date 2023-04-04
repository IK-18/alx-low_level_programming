#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - removes the first node
 * @head: list
 *
 * Return: value of removed node
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (!head || !*head)
		return (0);
	tmp = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = tmp;
	return (n);
}

