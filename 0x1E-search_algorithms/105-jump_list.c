#include <math.h>
#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers
 * @list: pointer to the head of the list to search in
 * @size: number of elements in list
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in list or if list is NULL,
 * your function must return NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step;
	listint_t *tmp1 = list, *tmp2 = list;

	if (!tmp1)
		return (NULL);
	step = sqrt(size);
	while (tmp1->n <= value)
	{
		printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
		if (tmp1->n == value)
			return (tmp1);
		while (tmp2->index < step && tmp2->next)
			tmp2 = tmp2->next;
		if (tmp2->n >= value || step >= size)
			break;
		while (tmp1->index < step && tmp1->next)
			tmp1 = tmp1->next;
		step += sqrt(size);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
		tmp1->index, (step < size ? step : size));
	while (tmp1->index < size)
	{
		printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
		if (tmp1->n == value)
			return (tmp1);
		if (tmp1->next)
			tmp1 = tmp1->next;
		else
			break;
	}
	printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
	if (tmp1->n == value)
		return (tmp1);
	return (NULL);
}
