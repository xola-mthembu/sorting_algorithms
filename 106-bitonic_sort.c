#include "sort.h"

/**
 * bitonic_merge - Merges and sorts a bitonic sequence.
 * @array: The array to sort.
 * @size: Total size of the array.
 * @start: Starting index of the sequence to merge.
 * @seq_size: Size of the sequence to sort.
 * @direction: Ascending (1) or descending (0).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size, int direction)
{
	size_t i, j;
	int temp;

	if (seq_size < 2)
		return;

	for (i = start; i < start + seq_size / 2; i++)
	{
		j = i + seq_size / 2;
		if ((array[i] > array[j]) == direction)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	bitonic_merge(array, size, start, seq_size / 2, direction);
	bitonic_merge(array, size, start + seq_size / 2, seq_size / 2, direction);
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence.
 * @array: The array to sort.
 * @size: Total size of the array.
 * @start: Starting index of the sequence to sort.
 * @seq_size: Size of the sequence to sort.
 * @direction: Ascending (1) or descending (0).
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, size_t seq_size, int direction)
{
	if (seq_size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", seq_size, size, direction ? "UP" : "DOWN");
	print_array(array + start, seq_size);

	bitonic_sort_rec(array, size, start, seq_size / 2, 1);
	bitonic_sort_rec(array, size, start + seq_size / 2, seq_size / 2, 0);
	bitonic_merge(array, size, start, seq_size, direction);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}

