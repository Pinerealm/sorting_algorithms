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
	printf("Before the helper call\n");
	quick_sort_helper(array, 0, size, size);
}

/**
 * quick_sort_helper - helper function for quick sort
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: total size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		printf("p: %d\n", p);
		printf("Before the left call\n");
		quick_sort_helper(array, lo, p - 1, size);
		printf("After the left call\n");
		printf("Before the right call\n");
		quick_sort_helper(array, p + 1, hi, size);
		printf("After the right call\n");
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
	int p_idx = lo - 1, idx;

	idx = lo;
	while (idx < hi)
	{
		if (array[idx] <= pivot)
		{
			p_idx++;
			if (p_idx != idx)
			{
				array[p_idx] ^= array[idx];
				array[idx] ^= array[p_idx];
				array[p_idx] ^= array[idx];
				print_array(array, size);
			}
		}
		idx++;
	}
	if (array[p_idx + 1] > pivot)
	{
		array[p_idx + 1] ^= array[hi];
		array[hi] ^= array[p_idx + 1];
		array[p_idx + 1] ^= array[hi];
		print_array(array, size);
	}

	return (p_idx + 1);
}
