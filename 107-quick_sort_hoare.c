#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array containing elements
 * @idx1: Index of the first element
 * @idx2: Index of the second element
 */
void swap(int *array, int idx1, int idx2)
{
	int temp;

	if (idx1 != idx2)
	{
		temp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = temp;
		/* printf("Swapped: %d <-> %d\n", array[idx1], array[idx2]); */
	}
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare_recursive - Recursively performs quicksort
 * using Hoare's partition
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort_hoare_recursive(int *array, int low, int high,
		size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quicksort_hoare_recursive(array, low, pivot, size);
		quicksort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in
 * ascending order using Quick sort (Hoare's partition)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}
