#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Description: Prints each element of an array of integers, followed by a
 * newline. Elements are separated by commas and spaces.
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; array && i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
