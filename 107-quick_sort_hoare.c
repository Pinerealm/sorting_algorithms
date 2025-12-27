#include "sort.h"

static void swap_int(int *a, int *b);
static int partition_hoare(int *array, int lo, int hi, size_t size);
static void quick_sort_rec(int *array, int lo, int hi, size_t size);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * quick sort algorithm and the Hoare partition scheme
 *
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
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
		int p = partition_hoare(array, lo, hi, size);

		quick_sort_rec(array, lo, p, size);
		quick_sort_rec(array, p + 1, hi, size);
	}
}

/**
 * partition_hoare - partitions the array and returns the pivot index
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: total size of the array
 *
 * Return: the pivot index
 */
int partition_hoare(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j == hi ? j - 1 : j);

		swap_int(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
