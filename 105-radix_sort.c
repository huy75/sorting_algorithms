#include "sort.h"

/**
 * get_max- finds the largest element in array
 * @array: pointer to array
 * @size: size of the array
 * Return: largest integer in array
 */

int get_max(int *array, int size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - sorts an array of ints in ascending order using Radix sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int count = 0, i, j, k = 0, m = 0;
	int *output;
	int digit = 1;
	int max_element;

	if (array == NULL || size < 2)
		return;
	output = malloc((sizeof(int) * size));
		if (!output)
			return;
	max_element = get_max(array, size);
	while (max_element >= 1)
	{
		max_element = max_element / 10;
		count += 1;
	}
	for (j = 0; j < count; j++)
	{
		while (m < (int)size)
		{
			for (i = 0; i < (int)size; i++)
			{
				if ((array[i] / digit) % 10  == k)
				{
					output[m] = array[i];
					m++;
				}
			}
			k++;
		}
		for (i = 0; i < (int) size; i++)
			array[i] = output[i];
		print_array(array, size);
		k = 0;
		m = 0;
		digit = digit * 10;
	}
	free(output);
}
