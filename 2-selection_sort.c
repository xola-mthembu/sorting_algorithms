#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: Goes through the array to find the minimum element and swaps
 * it with the first unsorted element.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (i != min_idx)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
