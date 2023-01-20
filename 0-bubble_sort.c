#include "sort.h"

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
