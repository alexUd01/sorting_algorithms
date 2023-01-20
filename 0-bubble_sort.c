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

	if (check_if_sorted(array, size))
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
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
