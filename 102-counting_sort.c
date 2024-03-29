#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0;
	size_t i;

	if (!array || size < 2)
		return;
	/* Find the max (arrays with positive integers only) */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= (size_t) max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Calculate the position of each element in the output array */
	for (i = 1; i <= (size_t) max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
