#include "sort.h"
/**
* swap_ints - Swaps two integers.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*
* This function swaps the values of two integers pointed to by 'a' and 'b'.
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sorting_using_lomuto - Sorts a subarray using the Lomuto partition sche
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @left: Index of the left boundary of the subarray.
 * @right: Index of the right boundary of the subarray.
 *
 * Return: Lomuto partition scheme. It partitions the
 * subarray around a pivot element
 * and recursively sorts the partitions.
*/
int sorting_using_lomuto(int *array, size_t size, int left, int right)
{
	int *pvt, above, below;

	pvt = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pvt)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pvt)
	{
		swap_ints(array + above, pvt);
		print_array(array, size);
	}

	return (above);
}

/**
* quick_sort_recursive - Recursively sorts an array using
* the quicksort algorithm.
* @array: Pointer to the array to be sorted.
* @size: Size of the array.
* @left: Index of the left boundary of the subarray.
* @right: Index of the right boundary of the subarray.
*
* This function recursively sorts an array of integer
* in ascending order using
* the quicksort algorithm. It partitions the array
* using the Lomuto partition scheme
* and recursively sorts the partitions.
*/
void quick_sort_recursive(int *array, size_t size, int left, int right)
{
	int index;

	if (right - left > 0)
	{
		index = sorting_using_lomuto(array, size, left, right);
		quick_sort_recursive(array, size, left, index - 1);
		quick_sort_recursive(array, size, index + 1, right);
	}
}

/**
* quick_sort - Sorts an array of integers in
* ascending order using quicksort.
* @array: Pointer to the array to be sorted.
* @size: Size of the array.
* This function sorts an array of integers in ascending
* order using the quicksort
* algorithm. It first checks if the array is valid and
* has more than one element,
* then calls the recursive quick_sort_recursive
* function to perform the sorting.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
