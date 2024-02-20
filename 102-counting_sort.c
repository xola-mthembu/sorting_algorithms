#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k = 0;
	size_t i;

	if (!array || size < 2)
		return;

	/* Find the largest element in the array */
	for (i = 0; i < size; i++)
		if (array[i] > k)
			k = array[i];

	/* Allocate memory for the count array and initialize it */
	count = calloc((k + 1), sizeof(int));
	output = malloc(size * sizeof(int));
	if (!count || !output)
		return;

	/* Store the count of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Change count[i] so it contains the actual position of this element in output */
	for (i = 1; i <= (size_t)k; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size; i > 0; i--)
	{
		output[count[array[i-1]] - 1] = array[i-1];
		count[array[i-1]]--;
	}

	/* Copy the output array to array, so that array now contains sorted elements */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(count, k + 1); /* As per requirement */

	free(count);
	free(output);
}
