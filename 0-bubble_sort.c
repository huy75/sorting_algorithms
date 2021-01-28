#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array using bubble sort
 * @array: array of ints
 * @size: number of elements in array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, iterate = size;
	int tmp;
	bool swapped = false;

	if (!array || size == 0)
		return;

	while (swapped == false)
	{
		swapped = true;
		/* printf("Swap? %s\n", swapped ? "true" : "false"); */
		for (i = 0; i < iterate - 1; i++) /* largest element at the end */
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
		/*printf("After swapping %d and %d\n", array[i], array[i + 1]);*/
				print_array(array, size);
			}
			swapped = false;
		}
		iterate--;
	}
}
