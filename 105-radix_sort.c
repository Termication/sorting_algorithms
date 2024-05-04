#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum element from an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: Maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * _counting_sort - Perform counting sort according to
 * the digit represented by exp
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Exponent representing the current significant digit
 */
void _counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers using Radix sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	size_t exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		_counting_sort(array, size, exp);
		print_array(array, size);
	}
}
