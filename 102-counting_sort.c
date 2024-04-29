#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function sorts an array of
 * integers in ascending order using
 * the Counting sort algorithm. It creates a count
 * array to store the count of each
 * element and then modifies the original array based on the count array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value, j, *count_array, *aux;
	size_t i;

	if (!array || size < 2)
		return;
	max_value = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	count_array = calloc((max_value + 1), sizeof(int));
	if (!count_array)
		return;
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < max_value; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, max_value + 1);
	aux = malloc(sizeof(int) * size);
	if (!aux)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		aux[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = aux[i];
	}
	free(aux);
	free(count_array);
}
