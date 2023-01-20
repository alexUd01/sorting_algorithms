#include "sort.h"

/**
 * check_if_sorted - a function that checks if an array of int is already
 * sorted.
 * @arr: the array of integers
 * @size: the size of the array
 * Return: returns 1 if sorted, 0 otherwise
 */
int check_if_sorted(int *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

/**
 * bubble_sort - a function that sorts an array of integers using bubble sort
 * algorithm.
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (check_if_sorted(array, size))
			return;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
