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
	int *t_array = NULL;

	if (array == NULL || size < 2)
		return;
	t_array = malloc(sizeof(int) * size);
	if (t_array == NULL)
		return;

	merge_sort_helper(array, t_array, 0, size - 1);
	free(t_array);
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
	size_t mid = 0, sum;

	if (start < end)
	{
		
		sum = start + end;
		if (sum % 2 != 0)
			mid = sum / 2;
		else if (end - start == 1)
			mid = start;
		else
			mid = (sum - 1) / 2;

		merge_sort_helper(array, t_array, start, mid);
		merge_sort_helper(array, t_array, mid + 1, end);
		merge(array, t_array, start, mid, end);
	}
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
	size_t i = start, j = mid + 1, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start + 1);
	printf("[right]: ");
	print_array(array + mid + 1, end - mid);

	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
			t_array[k++] = array[i++];
		else
			t_array[k++] = array[j++];
	}

	while (i <= mid)
		t_array[k++] = array[i++];
	while (j <= end)
		t_array[k++] = array[j++];
	for (i = start, k = 0; i <= end; i++, k++)
		array[i] = t_array[k];

	printf("[Done]: ");
	print_array(array + start, end - start + 1);

}
