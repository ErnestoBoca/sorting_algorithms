#include "sort.h"
/**
 * partition - divides the array into to parts
 * where the left part contains values less or equal than the pivot
 * The pivot is the last element of the array
 * @array: the array
 * @start: the start os the array
 * @end: the end of the array
 * @size: the size of the array
 * Return: the position of the pivot
*/
int partition(int array[], int start, int end, int size)
{
	int i, j, aux, pivot;

	j = start;
	i = start - 1;
	pivot = array[end - 1];

	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (j != i)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
		j++;
	}
	return (i);
}

/**
 * quick_recursive - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: the array
 * @start: the start os the partition
 * @end: the end of the partition
 * @size: the size of the array
 * Return: nothing
*/
void quick_recursive(int *array, int start, int end, int size)
{
	int pivot_pos;

	if (start >= end)
		return;

	pivot_pos = partition(array, start, end, size);
	quick_recursive(array, start, pivot_pos, size);
	quick_recursive(array, pivot_pos + 1, end, size);
}
/**
 * quick_sort - calls the quick sort recursive function
 * @array: the unsorted array
 * @size: the size of the array
 * Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, 0, size, size);

}
