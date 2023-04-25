#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, and the Knuth gap sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int value;
	size_t gap = 1, a, b;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap *= 3 + 1;
	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			value = array[a];
			b = a;
			while (b >= gap && array[b - gap] > value)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
