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
 *counting_sort - uses the Counting sort algorithm to sort an array of integers
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, k;

	if (!array || size < 2)
		return;
	k = get_max(array, size);
	/* create an array count of size k + 1 */
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	/* initialize all elements of count array to 0 */
	for (i = 0; i <= k + 1; i++)
		count[i] = 0;
	/* count of each element stored */
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/* store the cumulative sum of the counts */
	for (i = 0; i < k + 1; i++)
		count[i + 1] += count[i];
	print_array(count, k + 1);
	/* create an array for the sorted output */
	output = malloc(sizeof(int) * size);
		if (!output)
			return;
	/* sort the array with corresponding cumulative sum */
	for (i = 0; i < size; i++)
	{
		/* ex. 19 -> cumulative sum = 3. So sorted at (3-1) = 2 */
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* copy the output */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
