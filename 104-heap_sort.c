#include "sort.h"

void heapify_down(int *array, size_t s, size_t root, size_t size);
/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int tmp;

	if (size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify_down(array, size, (size_t)i, size);

	/* Heap sort */
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		if (i != 0)
			print_array(array, size);
		heapify_down(array, (size_t)i, 0, size);
	}
}

/**
 * heapify_down - Maintains the heap property of a
 * subtree rooted at a given node by moving elements
 * down the heap when necessary.
 *
 * @array: The array to be sorted.
 * @s: The size of the heap.
 * @root: The index of the root of the subtree.
 * @size: The size of the array.
 */
void heapify_down(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int tmp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		tmp = array[root];
		array[root] = array[max];
		array[max] = tmp;
		print_array(array, size);
		heapify_down(array, s, max, size);
	}
}
