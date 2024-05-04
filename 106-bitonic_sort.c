#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge the two subarrays in ascending or descending order
 * @array: Array of integers
 * @low: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;
		int temp;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				printf("Merging [%lu/%lu] (", count, count * 2);
				printf(dir ? "UP):\n" : "DOWN):\n");
				print_array(array + low, count);
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively apply the bitonic merge operation
 * @array: Array of integers
 * @low: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		printf("Merging [%lu/%lu] (", count, count * 2);
		printf(dir ? "UP):\n" : "DOWN):\n");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);

		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers using Bitonic sort algorithm
 * @array: Array of integers
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
