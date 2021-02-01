#include "sort.h"
/**
 * shell_sort - shell_sort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (!array || size < 2)
		return;

	gap = 0;
	while (gap < size)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;

	for (; gap; gap = (gap - 1) / 3)
	{
		/**
		 * Do a gapped insertion sort for this gap size.
		 * The first gap elements a[0..gap-1] are already in gapped
		 * order keep adding one more element until the entire array is
		 * gap sorted
		 */
		for (i = gap; i < size; i++)
		{
			/**
			 * add a[i] to the elements that have been gap sorted
			 * save a[i] in temp and make a hole at position i
			 */
			temp = array[i];
			/**
			 * shift earlier gap-sorted elements up until the
			 * correct location for a[i] is found
			 */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			/**
			  * put temp (the original a[i]) in its correct location
			  */
			array[j] = temp;
		}
		print_array(array, size);
	}
}
