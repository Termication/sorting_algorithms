#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using
*               the Bubble sort algorithm
*
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (!array || size == 0)
		return;

	for (j = 0; j < size - 1; ++j)
	{
		int sorted = 1; /* Flag to check if array is already sorted */

		for (i = 0; i < size - j - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				sorted = 0;
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}

		/* If no swaps were made in the inner loop, array is already sorted */
		if (sorted)
			break;
	}
}
