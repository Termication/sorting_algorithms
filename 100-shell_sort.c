#include "sort.h"
#include <stdio.h>

/**
 * swap_items - Swaps two items in an array.
 * @array: The array containing the items to be swapped.
 * @i: The index of the first item to be swapped.
 * @j: The index of the second item to be swapped.
 *
 * This function swaps the items at the given indices in the array.
 */
void swap_items(int *array, int i, int j)
{
	int tmp;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * shell_sort - Sorts an array of integers using the shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers in ascending order using the
 * shell sort algorithm.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (size < 2)
	{
		return;
	}

	gap = 1;
	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
