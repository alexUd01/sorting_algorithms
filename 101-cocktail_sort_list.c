#include "sort.h"

/**
 * swap_nodes - a helper function that swaps two adjacent nodes of a doubly
 *              linked list.
 * @ptr1: a pointer to a node
 * @ptr2: a pointer to the second node
 * Return: returns the address of the swapped node
 */
listint_t *swap_nodes(listint_t *ptr, listint_t **head)
{
	listint_t *temp;

	temp = ptr->next;
	if (temp->next != NULL)  /* not last node of the list */
		temp->next->prev = ptr;
	temp->prev->next = temp->next;
	temp->next = ptr;
	temp->prev = ptr->prev;
	if (ptr->prev != NULL)  /* not first node of the list */
		ptr->prev->next = temp;
	ptr->prev = temp;

	if (temp->prev == NULL)
		*head = temp;

	return (temp);
}

/**
 * coctail_sort_list - a function that sorts a list in ascending order using
 *                     coctail shaker sorting algorithm.
 * @list: the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int swapped;

	if (!list || !(*list) || (!(*list)->prev && !(*list)->next))
		return;

	ptr = *list;
	do {
		/* forward traversal */
		swapped = 0;
		while (ptr->next->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				ptr = swap_nodes(ptr, list);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr = ptr->next;
		}
		if (!swapped)
			break;

		/* backward traversal */
		swapped = 0;
		while (ptr != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				ptr = swap_nodes(ptr, list);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr = ptr->prev;
		}
		if (!swapped)
			break;

		/* ptr is now == NULL. Reinitialize it to first node */
		ptr = *list;

	} while (swapped);
}




/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
