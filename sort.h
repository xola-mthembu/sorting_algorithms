#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 *
 * Description: Doubly linked list node structure
 * for the Holberton project. This structure is used for storing
 * integers and pointers to the previous and next elements in the list.
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes for printing */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
