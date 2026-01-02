#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: void
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Restores the heap property by sifting down.
 * @array: Array of integers.
 * @size: Size of the full array.
 * @start: Root index of the subtree to sift down.
 * @end: Last index of the heap.
 */
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swap;

	root = start;
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		swap_ints(&array[root], &array[swap]);
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	/* Build max heap (sift-down heapify) */
	start = (size - 2) / 2 + 1;
	while (start > 0)
	{
		start--;
		sift_down(array, size, start, size - 1);
	}

	/* Extract elements from heap one by one */
	end = size - 1;
	while (end > 0)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
