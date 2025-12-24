#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t idx = 0, idx2, min_idx;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (idx < size - 1)
	{
		min_idx = idx;
		for (idx2 = idx + 1; idx2 < size; idx2++)
		{
			if (array[idx2] < array[min_idx])
				min_idx = idx2;
		}
		if (min_idx != idx)
		{
			tmp =  array[idx];
			array[idx] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
		idx++;
	}
}
