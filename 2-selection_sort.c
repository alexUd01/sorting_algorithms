#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t new_min, temp;

	for (i = 0; i < size-1; i++)
	{
		new_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[new_min])
			{
				new_min = j;
			}
		}

		if (new_min != i)
		{
			temp = array[i];
			array[i] = array[new_min];
			array[new_min] = temp;
			print_array(array, size);
		}
	}
}
