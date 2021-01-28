#include "sort.h"
#include <stdbool.h>

/**
 * swapp - Swaps specified array elements then prints array
 * @array: Array to swap elements
 * @size: Size of array
 * @i: First index to swap
 * @j: Second index to swap
 */

/**
void swap(int *array, size_t size, int i, int j)
{
	int tmp;

	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;

	print_array(array, size);
}

*/

/**
 * bubble_sort - sorts an array using bubble sort
 * @array: array of ints
 * @size: number of elements in array
 * Return: void
 */
/* Output seems ok*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array && size > 1 )
	{
		for (i = 0; i < size; i++)
		{
			/* size - 1 to avoid largest elemnt in the final place */
			/* so that no need to double check */
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					print_array(array, size);
				}
			}
		}
	}
	else
		return;

}



/*First version of the code
 * output? needs improvement
 */

/**

void bubble_sort(int *array, size_t size)
{
	size_t i;

	while (array)
	{
		for (i = 0; i < size -1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, size, i, i + 1);
				print_array(array, size);
			}
		}
	}
	return;
}


*/
