#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to the head of list
 *
 * Return: sum of all the data
 */

int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *tmp;

	if (!head)
		return (total);
	while (head->prev)
		head = head->prev;
	tmp = head;
	while (tmp)
	{
		total += tmp->n;
		tmp = tmp->next;
	}
	return (total);
}
