#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a: pointer to a
 * @b: ppointer to b
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - lomuto partition
 * @array: array
 * @low: start
 * @high: end
 * @size: array size
 *
 * Return: index of pivot
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * recursion - recursive sorting help
 * @array: array
 * @size: size
 * @low: low
 * @high: high
 */

void recursion(int *array, size_t size,  int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		recursion(array, size, low, pivot - 1);
		recursion(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - performs the quick sort algorithm
 * @array: an array
 * @size: size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	recursion(array, size, 0, size - 1);
}
