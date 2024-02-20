#include "sort.h"

/**
 * find_max - Finds the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * Return: The maximum integer value in the array.
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max); /* Corrected to include parentheses */
}

/**
 * init_count_array - Initializes the count array for counting sort.
 * @count: Pointer to the count array.
 * @array: The original array to be sorted.
 * @size: Size of the original array.
 */
void init_count_array(int *count, int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[array[i]] += 1;
	}
}

/**
 * apply_counting_sort - Applies counting sort logic to sort the array.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @max: Maximum value in the array.
 */
void apply_counting_sort(int *array, size_t size, int max)
{
	int *count, *output;
	size_t i;

	count = calloc(max + 1, sizeof(int));
	if (count == NULL)
		return;

	init_count_array(count, array, size);

	for (i = 1; i <= (size_t)max; i++)
	{
		count[i] += count[i - 1];
	}

	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]] -= 1;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(count);
	free(output);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);

	apply_counting_sort(array, size, max);
}
