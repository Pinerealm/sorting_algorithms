#include "sort.h"
/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @arr: array
 * @n: size of array
 */
void shell_sort(int arr[], int n)
{
	int a, b, value, gap = 1;

	while (gap < n / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (a = gap; a < n; a++)
		{
			value = arr[a];
			b = a;
			while (b > gap - 1 && arr[b - gap] > value)
			{
				arr[b] = arr[b - gap];
				b = b - gap;
			}
			arr[b] = value;
		}
		gap = (gap - 1) / 3;
		print_array(arr, n);
	}
}
