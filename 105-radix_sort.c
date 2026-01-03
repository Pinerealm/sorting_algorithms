#include "sort.h"

/**
 * get_max - Finds the maximum value in an integer array
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * Return: The maximum value found in the array
 */
static int get_max(const int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_exp - Stable counting sort of @array by digit at @exp.
 * @array: Array of integers.
 * @size: Size of the array.
 * @exp: Significant digit exponent (1, 10, 100, ...).
 *
 * Return: 1 on success, 0 on allocation failure.
 */
static int counting_sort_exp(int *array, size_t size, int exp)
{
	size_t i;
	int count[10], *output, digit;

	output = malloc(sizeof(int) * size);
	if (!output)
		return (0);

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit] += 1;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	return (1);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD radix sort.
 * @array: Array of integers (assumed >= 0).
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		if (!counting_sort_exp(array, size, exp))
			return;
		print_array(array, size);
	}
}
