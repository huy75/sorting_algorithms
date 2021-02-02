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

	size_t i;
	int output[size];
	int digit = 1;
	int max_element = get_max(array, size);

	while (max_element / digit > 0)
{

		int bucket[10] = {0};
		/* Count the elements */
		for (i = 0; i < size; i++)
			bucket[(array[i] / digit) % 10]++;
		/* Calculate the cumulative sum of counts */
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		/* Place the elements in a sorted order */
		for (i = size - 1; i < size; i--)
			output[--bucket[(array[i] / digit) % 10]] = array[i];
		/* copy the output */
		for (i = 0; i < size; i++)
			array[i] = output[i];
		print_array(array, size);

		digit *= 10;

	}
}
