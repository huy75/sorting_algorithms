#include "sort.h"
/**
 * merge_sort - sorts an array of ints in ascending order using Merge sort algo
 * @array: array to sort
 * @size: size of the array
 * Implement the top-down merge sort algorithm
 * Size of the left array should always be <= right array
 * Left array is sorted first
 * Malloc/free can be called only once
 * Return: void
 */


void merge_sort(int * array, size_t size)
{
	int *tmp;
	size_t i;

	if(!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	for (i = 0; i < size; i++)
		tmp[i] = array[i];
	top_down(tmp, 0, size, array);
	free(tmp);
}

/**
 * top_down - splits the array and sort recursively
 * @array: array to sort
 * @left: first  element
 * @right:last element
 * @tmp: temp array to sorting elements
 */
void top_down(int *array, size_t left, size_t right, int *tmp)
{
	size_t mid;

	mid = (left + right) / 2;
	if (right - left < 2)
		return;
	top_down(tmp, left, mid, array);
	top_down(tmp, mid, right, array);
	merge(array, left, right, tmp);
}


/**
 * merge - merge sorted arrays
 * @array: array to sort
 * @left: first index of the array
 * @right: last index of the array
 * @tmp: temp array to sort elements
 */

void merge(int * array, size_t left, size_t right, int *tmp)
{
	size_t i, j, k, mid;

	i = left;
	j = mid = (left + right) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	for (k = left; k < right; k++)
		if (i < mid && ( j >= right || array[i] <= array[j]))
		{
			tmp[k] = array[i++];
		}
		else
		{
			tmp[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(tmp + left, right - left);
}
