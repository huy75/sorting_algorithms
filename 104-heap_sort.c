#include "sort.h"

/**
 * swap_elem - swap value of array elements
 * @array: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *array, size_t size, int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * sift_down - Builds heap form bottom up
 * @array: List to be sorted
 * @start: Root ot the heap
 * @end: Last element of the heap
 * @size: Size of array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, swap;

	root = start; /* while the root has at least one child */
	while ((root * 2) + 1 <= end)
	{
		/* Points to the left child */
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
		{
			/* Swap root and left child */
			swap = child;
		}
		/**
		 * If the child has a sibling and
		 * the child's value is less than its sibling's...
		 */
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			/* ...then point to the right child instead */
			swap = child + 1;
		}
		/* If one child is greater than other */
		if (swap != root)
		{
			swap_elem(array, size, &array[root], &array[swap]);
			root = swap;
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - Arranges heap so largest number is root
 * @array: array (for print)
 * @size: size of array (for print)
 */
void heapify(int *array, size_t size)
{
	int start;

	/**
	 * Last non-leaf parent node
	 */
	start = (size / 2) - 1;

	while (start >= 0)
	{
		/**
		 * all nodes below the start index are in heap order
		 */
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sort list in ascending order Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	end = size - 1; /* max heap order */
	heapify(array, size);
	printf("after heapify\n");
	print_array(array, size);
	while (end)
	{
		/**
		 * swap the root (max value) with the last element
		 */
		swap_elem(array, size, &array[end], &array[0]);
		end--;
		/**
		 * put the heap back in max-heap order
		 */
		sift_down(array, 0, end, size);
	}
}
