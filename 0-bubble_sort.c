#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * bubble sort algorithm
 *
 * @array: the array of integers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, i = 0;

	if (array == NULL || size < 2)
		return;

	while (size - i)
	{
		for (idx = 1; idx < size; idx++)
		{
			if (array[idx - 1] > array[idx])
			{
				/* swap integers using XOR */
				array[idx - 1] ^= array[idx];
				array[idx] ^= array[idx - 1];
				array[idx - 1] ^= array[idx];
				print_array(array, size);
			}
		}
		i++;
	}
}
