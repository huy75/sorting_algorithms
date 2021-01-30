#include "sort.h"

/**
 * swap - Swap two values in array
 * @array: Array
 * @size: Size of array
 * @i: Value to swap
 * @j: Value to swap
 *
 * Return: None
 */
void swap(int *array, size_t size, int i, int j)
{
	int tmp;

	tmp = array[j];
	if (array[i] != array[j])
	{
		array[j] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - lomuto partition scheme
 * takes last element as pivot, and places all smaller
 * (smaller than pivot) to left of pivot and all greater
 * elements to right of pivot
 * @array: Array to partition
 * @lo: Lower bound
 * @hi: Upper bound
 * @size: Size of array
 *
 * Return: Pivot of array
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1;
	int j;
	int pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, size, i, j);
		}
	}
	++i;
	swap(array, size, i, hi);
	return (i);
}


/**
 * quicksort - Sort array recursively using pivot
 * @array: Array to sort
 * @lo: Lower index bound
 * @hi: Upper index bound
 * @size: Size of array
 *
 * Return: None
 */
void quicksort(int *array, int lo, int hi, size_t size)
{

	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);

	}
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
