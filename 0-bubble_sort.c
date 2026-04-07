#include "sort.h"

/**
 * bubble_sort - sorts by getting higher numbers past smaller numbers
 * eg 19, 48, 71, 99, 13, 52, 96, 73, 86, 7, will push 99 up to the top
 * first before getting any others
 * @array: the numbers
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, sorted;
	int tmp;

	if (array == NULL)
		return;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
