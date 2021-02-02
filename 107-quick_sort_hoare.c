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
	int pivot = array[lo];
	int i = lo, j = hi;
	int temp;

	while (1)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (j);
       		temp = array[j];
       		array[j] = array[i];
       		array[i] = temp;
       		print_array(array, size);
	}
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
		quicksort(array, lo, p, size);
		quicksort(array, p + 1, hi, size);

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
