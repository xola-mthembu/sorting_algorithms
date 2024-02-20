#include "sort.h"
#include <stdio.h>

/**
 * print_array_portion - Prints a portion of an array
 * @array: The array to be printed
 * @begin: The starting index
 * @end: The ending index, exclusive
 */
void print_array_portion(const int *array, int begin, int end)
{
	int i;

	for (i = begin; i < end; i++)
	{
		if (i > begin)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * merge - Merges two subarrays of array.
 * @array: Array to be sorted.
 * @left: Temporary array for the left subarray.
 * @right: Temporary array for the right subarray.
 * @start: Start index of the left subarray in the main array.
 * @mid: Middle index, separating left and right subarrays.
 * @end: End index of the right subarray in the main array.
 */
void merge(int *array, int *left, int *right, int start, int mid, int end)
{
	int i = 0, j = 0, k = start;
	int left_size = mid - start, right_size = end - mid;

	printf("Merging...\n[left]: ");
	print_array_portion(left, 0, left_size);
	printf("[right]: ");
	print_array_portion(right, 0, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array_portion(array, start, end);
}

/**
 * top_down_split_merge - Recursively sorts and merges subarrays.
 * @buffer: Buffer array for merging.
 * @start: Starting index of subarray to sort.
 * @end: Ending index of subarray to sort.
 * @array: Original array to be sorted.
 */
void top_down_split_merge(int *buffer, size_t start, size_t end, int *array)
{
	size_t mid, i;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;
	top_down_split_merge(array, start, mid, buffer);
	top_down_split_merge(array, mid, end, buffer);
	merge(buffer, array + start, array + mid, start, mid, end);

	for (i = start; i < end; i++)
		array[i] = buffer[i];
}

/**
 * merge_sort - Sorts an array using the Merge sort algorithm.
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
		buffer[i] = array[i];

	top_down_split_merge(buffer, 0, size, array);
	free(buffer);
}
