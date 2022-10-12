#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm and the Lomuto partition scheme
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
 * quick_sort_rec - sorts an array of integers in ascending order using the
 * Quick sort algorithm and the Lomuto partition scheme
 *
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: size of the array
 */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_rec(array, lo, p - 1, size);
		quick_sort_rec(array, p + 1, hi, size);
	}
}

/**
 * partition - sorts an array of integers in ascending order using the
 * Quick sort algorithm and the Lomuto partition scheme
 *
 * @array: array to sort
 * @lo: lower index
 * @hi: higher index
 * @size: size of the array
 *
 * Return: the partition index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j, tmp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[hi])
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
