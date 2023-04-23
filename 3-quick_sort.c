#include "sort.h"
#include <stdio.h>
void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm and the Lomuto partition scheme
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper function for quick sort
 * @array: array to sort
 * @lo: lowest index of the current array
 * @hi: highest index of the current array
 * @size: original array size
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * partition - partitions the array and returns the pivot index
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: total size of the array
 *
 * Return: the pivot index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int s_idx = lo - 1;

	while (lo < hi)
	{
		if (array[lo] <= pivot)
		{
			s_idx++;
			if (s_idx != lo)
			{
				array[s_idx] ^= array[lo];
				array[lo] ^= array[s_idx];
				array[s_idx] ^= array[lo];
				print_array(array, size);
			}
		}
		lo++;
	}
	if (array[s_idx + 1] != array[hi])
	{
		array[s_idx + 1] ^= array[hi];
		array[hi] ^= array[s_idx + 1];
		array[s_idx + 1] ^= array[hi];
		print_array(array, size);
	}

	return (s_idx + 1);
}
