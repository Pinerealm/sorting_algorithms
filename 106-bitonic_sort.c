#include <stdio.h>
#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merges a bitonic sequence into a sorted sequence
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the sequence to merge
 * @count: Number of elements in the sequence to merge
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 * @size: Total size of the array
 *
 * Description: This function recursively merges a bitonic sequence by
 * comparing and swapping elements at distance k, then recursively merging
 * the two halves. A bitonic sequence is one that first increases then
 * decreases, or is entirely increasing/decreasing.
 *
 * Return: void
 */
static void bitonic_merge(int *array, size_t low, size_t count, int dir,
		size_t size)
{
	size_t i, k;

	if (count < 2)
		return;

	k = count / 2;
	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
			swap_ints(&array[i], &array[i + k]);
	}

	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * bitonic_seq - Recursively sorts an array using the bitonic sort algorithm
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the sequence to sort
 * @count: Number of elements in the sequence to sort
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 * @size: Total size of the array
 *
 * Description: This function implements the bitonic sort algorithm by
 * recursively dividing the sequence into two halves, sorting them in
 * opposite directions, and then merging them into a bitonic sequence.
 * The function prints the array state before and after each merge operation.
 *
 * Return: void
 */
static void bitonic_seq(int *array, size_t low, size_t count, int dir,
		size_t size)
{
	size_t k;

	if (count < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", (unsigned long)count,
		(unsigned long)size, dir ? "UP" : "DOWN");
	print_array(array + low, count);

	k = count / 2;
	bitonic_seq(array, low, k, 1, size);
	bitonic_seq(array, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);

	printf("Result [%lu/%lu] (%s):\n", (unsigned long)count,
		(unsigned long)size, dir ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                Bitonic sort.
 * @array: Array of integers.
 * @size: Size of the array (assumed to be 2^k).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, 0, size, 1, size);
}
