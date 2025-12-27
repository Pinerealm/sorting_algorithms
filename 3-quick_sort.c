#include "sort.h"

static void swap_int(int *a, int *b);
static int partition_lomuto(int *array, int lo, int hi, size_t size);
static void quick_sort_rec(int *array, int lo, int hi, size_t size);

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
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - helper function for quick sort
 * @array: array to sort
 * @lo: lowest index of the current array
 * @hi: highest index of the current array
 * @size: original array size
 */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = partition_lomuto(array, lo, hi, size);

		quick_sort_rec(array, lo, p - 1, size);
		quick_sort_rec(array, p + 1, hi, size);
	}
}

/**
 * partition_lomuto - partitions the array and returns the pivot index
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: total size of the array
 *
 * Return: the pivot index
 */
int partition_lomuto(int *array, int lo, int hi, size_t size)
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
				swap_int(&array[s_idx], &array[lo]);
				print_array(array, size);
			}
		}
		lo++;
	}
	if (array[s_idx + 1] != array[hi])
	{
		swap_int(&array[s_idx + 1], &array[hi]);
		print_array(array, size);
	}

	return (s_idx + 1);
}

/**
 * swap_int - swaps two integers in place
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
