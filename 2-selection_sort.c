#include "sort.h"

/**
 * selection_sort - sorts by min each time
 * @array: array
 * @size: size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t small, i, j;
	int tmp;

	if (size == 0 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[small])
				small = j;
		}
		if (i != small)
		{
			tmp = array[i];
			array[i] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
	}
}
