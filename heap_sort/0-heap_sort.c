#include <stdio.h>
#include "sort.h"

/**
 * heapify - Ensures that the given subtree is a heap
 * @array: Array to heapify
 * @size: Size of the array
 * @idx: Index of the subtree root
 * @total_size: Total size of the array
 */
void heapify(int *array, size_t size, size_t idx, size_t total_size)
{
	size_t largest;
	size_t left;
	size_t right;
	int temp;

	largest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		temp = array[idx];
		array[idx] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *	Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
