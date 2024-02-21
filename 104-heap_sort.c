#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Corrects a single violation of the heap property in a subtree
 * @array: the array representation of the heap
 * @start: subtree's root element index
 * @end: the last index of the heap
 * @size: total size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
		{
			return;
		} else
		{
			swap_ints(&array[root], &array[swap]);
			print_array(array, size);
			root = swap;
		}
	}
}

/**
 * heapify - Converts an array into a heap
 * @array: the array to heapify
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (size < 2)
		return;

	heapify(array, size);
	for (end = size - 1; end > 0; end--)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
