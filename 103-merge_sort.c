#include "sort.h"

/**
 * merge - Merges two subarrays of array.
 * @array: Array to be sorted.
 * @left: Temporary array to store left subarray.
 * @right: Temporary array to store right subarray.
 * @size: Number of elements in array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	size_t mid = size / 2;

	while (i < (int)mid && j < (int)(size - mid))
	{
		if (left[i] < right[j])
		{
			array[k++] = left[i++];
		}
		else
		{
			array[k++] = right[j++];
		}
	}

	while (i < (int)mid)
	{
		array[k++] = left[i++];
	}

	while (j < (int)(size - mid))
	{
		array[k++] = right[j++];
	}
}

/**
 * top_down_split_merge - Recursively sorts and merges subarrays.
 * @buffer: Buffer array for merging.
 * @start: Starting index of subarray to sort.
 * @end: Ending index of subarray to sort.
 * @array: The original array to be sorted.
 */
void top_down_split_merge(int *buffer, size_t start, size_t end, int *array)
{
	size_t mid, i;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;
	top_down_split_merge(array, start, mid, buffer);
	top_down_split_merge(array, mid, end, buffer);
	merge(buffer + start, array + start, array + mid, end - start);

	for (i = start; i < end; i++)
	{
		array[i] = buffer[i];
	}
}

/**
 * merge_sort - Sorts an array in asc order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;
	size_t i;

	if (!array || size < 2)
		return;

	buffer = malloc(size * sizeof(int));
	if (!buffer)
		return;

	for (i = 0; i < size; i++)
	{
		buffer[i] = array[i];
	}

	top_down_split_merge(buffer, 0, size, array);
	free(buffer);
}
