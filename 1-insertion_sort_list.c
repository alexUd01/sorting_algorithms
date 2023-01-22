#include "sort.h"

/**
 * sort_func - a helper function that sorts a doubly linked list of integers
 * @ptr: a double pointer to the list of integers
 */
int sort_func(listint_t *ptr, listint_t **list)
{
	listint_t *temp;
	int swap_occured = 0;

	temp = ptr->next;
	while (ptr != NULL)
	{
		/* insert before the first node */
		if (ptr->prev == NULL && temp->n < ptr->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

			temp->next = ptr;
			temp->prev = NULL;
			ptr->prev = temp;
			*list = temp;
			print_list((const listint_t *)*list);
			return (0);
		}

		if (ptr->prev == NULL && ptr->n > temp->n)
		{
			/* first node of list is greater than temp->n */
			ptr->next = temp->next;
			temp->next = ptr;
			ptr->next->prev = ptr;
			temp->prev = ptr->prev;
			ptr->prev = temp;

			ptr = ptr->prev; /* ptr now points to temp */
			swap_occured = 1;
			print_list((const listint_t *)*list);
			continue;
		}

		ptr = ptr->prev;/*ptr now points to the node before temp*/
	}
	return (swap_occured);
}

/**
 * insertion_sort_list - a function that sorts a linked list in ascending
 * order using insertion sort algorithm
 * @list: a double pointer to the list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *temp;
	int n;

	if (list == NULL || *list == NULL)
		return;

	/* check if only one element is on the list */
	if ((*list)->prev == NULL && (*list)->next == NULL)
		return;

	/* TODO: If checker fails, try rewinding the doubly linked list. */

	ptr = *list;

	while (ptr != NULL)
	{
		temp = ptr->next;
		n = sort_func(ptr, list);
		if (n == 1)
			break;
		ptr = temp;
	}
}
