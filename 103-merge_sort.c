#include "sort.h"
#include <stdio.h>
void merge_sort_helper(int *array, int *t_array, size_t start, size_t end);
void merge(int *array, int *t_array, size_t start, size_t mid, size_t end);

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the top-down implementation of the merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_helper(array, tmp, 0, size);
	free(tmp);
}

/**
 * merge_sort_helper - helper function for merge_sort
 * @array: array to sort
 * @t_array: temporary array to store sorted elements
 * @start: start index of the array
 * @end: end index of the array
 */
void merge_sort_helper(int *array, int *t_array, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = start + (end - start) / 2;

	merge_sort_helper(array, t_array, start, mid);
	merge_sort_helper(array, t_array, mid, end);
	merge(array, t_array, start, mid, end);
}

/**
 * merge - merges two subarrays
 * @array: array to sort
 * @t_array: temporary array to store sorted elements
 * @start: start index of the array
 * @mid: middle of the array
 * @end: end index of the array
 */
void merge(int *array, int *t_array, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			t_array[k++] = array[i++];
		else
			t_array[k++] = array[j++];
	}

	while (i < mid)
		t_array[k++] = array[i++];
	while (j < end)
		t_array[k++] = array[j++];
	for (k = start; k < end; k++)
		array[k] = t_array[k];

	printf("[Done]: ");
	print_array(array + start, end - start);

}
