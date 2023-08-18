#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to head of doubly linked list
 * @n: new element to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *tmp, *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	tmp = *head;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = new;
	}
	new->next = tmp;
	*head = new;
	return (new);
}
