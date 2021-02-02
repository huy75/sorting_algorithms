#include "sort.h"

/**
 * partition - hoare partition scheme
 * takes first element as pivot, and places all smaller
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
	int pivot = array[hi];
	int i = lo - 1, j = hi + 1;
	int temp;

	while (1)
	{
		do {
			i += 1;
		} while (array[i] < pivot);
		do {
			j -= 1;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);

		temp = array[j];
		array[j] = array[i];
		array[i] = temp;

		print_array(array, size);
	}
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
		quicksort(array, p, hi, size);

	}
}

/**
 * quick_sort_hoare - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
