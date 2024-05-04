#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_values - Swap two elements in an array based on a specified order.
 * @arr: The array.
 * @index1: The index of the first element.
 * @index2: The index of the second element.
 * @ascending: Whether the sorting order is ascending (1) or descending (0).
 */
void swap_values(int arr[], int index1, int index2, int ascending)
{
	if (ascending == (arr[index1] > arr[index2]))
	{
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * merge_subarrays - Recursively merge bitonic sequences in both ascending and descending orders.
 * @arr: The array.
 * @low: The index of the first element in the subarray.
 * @count: The number of elements in the subarray.
 * @ascending: Whether the sorting order is ascending (1) or descending (0).
 */
void merge_subarrays(int arr[], int low, int count, int ascending)
{
	int mid, i;

	if (count > 1)
	{
		mid = count / 2;
		for (i = low; i < low + mid; i++)
			swap_values(arr, i, i + mid, ascending);
		merge_subarrays(arr, low, mid, ascending);
		merge_subarrays(arr, low + mid, mid, ascending);
	}
}

/**
 * bitonic_sort_recursive - Recursively applies the bitonic merge operation.
 * @arr: The array.
 * @low: The index of the first element in the subarray.
 * @count: The number of elements in the subarray.
 * @ascending: Whether the sorting order is ascending (1) or descending (0).
 * @size: The total size of the array.
 */
void bitonic_sort_recursive(int arr[], int low, int count, int ascending, int size)
{
	int mid;

	if (count > 1)
	{
		if (ascending >= 1)
		{
			printf("Merging [%d/%d] (UP):\n", count, size);
			print_array(&arr[low], count);
		}
		else
		{
			printf("Merging [%d/%d] (DOWN):\n", count, size);
			print_array(&arr[low], count);
		}
		mid = count / 2;
		bitonic_sort_recursive(arr, low, mid, 1, size);
		bitonic_sort_recursive(arr, low + mid, mid, 0, size);
		merge_subarrays(arr, low, count, ascending);
		if (ascending <= 0)
		{
			printf("Result [%d/%d] (DOWN):\n", count, size);
			print_array(&arr[low], count);
		}
		if (ascending >= 1)
		{
			printf("Result [%d/%d] (UP):\n", count, size);
			print_array(&arr[low], count);
		}
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int ascending = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, ascending, size);
}
