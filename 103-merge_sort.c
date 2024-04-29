#include "sort.h"
#include <stdio.h>
/**
 * merge_subarray - Merges two subarrays into a single sorted subarray
 *
 * @subarr: Pointer to the original array containing the subarrays
 * @buff: Temporary buffer array to store merged elements
 * @start: Starting index of the first subarray
 * @mid: Ending index of the first subarray and
 * starting index of the second subarray
 * @end: Ending index of the second subarray
 */
void merge_subarray(int *subarr, int *buff, size_t start,
		size_t mid, size_t end)
{
	size_t index1, index2, index3 = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + start, mid - start);

	printf("[right]: ");
	print_array(subarr + mid, end - mid);

	for (index1 = start, index2 = mid; index1 < mid && index2 < end; index3++)
		buff[index3] = (subarr[index1] < subarr[index2])
			? subarr[index1++] : subarr[index2++];
	for (; index1 < mid; index1++)
		buff[index3++] = subarr[index1];
	for (; index2 < end; index2++)
		buff[index3++] = subarr[index2];
	for (index1 = start, index3 = 0; index1 < end; index1++)
		subarr[index1] = buff[index3++];

	printf("[Done]: ");
	print_array(subarr + start, end - start);
}

/**
 * sorting_recursive - Sorts a subarray using the merge
 * sort algorithm recursively
 *
 * @subarray: Pointer to the original array containing the subarray
 * @buffer: Temporary buffer array to store merged elements
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 */
void sorting_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		sorting_recursive(subarray, buffer, start, middle);
		sorting_recursive(subarray, buffer, middle, end);
		merge_subarray(subarray, buffer, start, middle, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *pow;

	if (array == NULL || size < 2)
		return;

	pow = malloc(sizeof(int) * size);
	if (pow == NULL)
		return;

	sorting_recursive(array, pow, 0, size);

	free(pow);
}
