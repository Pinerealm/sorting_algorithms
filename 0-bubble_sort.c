#include "sort.h"
/**
 *swap - a function that swaps two integers
 *@a: first integer
 *@b: second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 *bubble_sort - a function that sorts elements of an array in ascending order
 *@array: array
 *@n: size of the array
 */
void bubble_sort(int *array, int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, n);
			}
		}
	}
}
