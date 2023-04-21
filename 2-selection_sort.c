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
	int min;

	if (array == NULL || size < 2)
		return;
	while (idx < size)
	{
		min = array[idx];
		for (idx2 = idx + 1; idx2 < size; idx2++)
		{
			if (array[idx2] < min)
			{
				min = array[idx2];
				min_idx = idx2;
			}
		}
		if (min != array[idx])
		{
			array[min_idx] = array[idx];
			array[idx] = min;
			print_array(array, size);
		}
		idx++;
	}
}
