#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1, 22, 20, 21, 2, 31, 32, 34, 41, 39, 47, 79, 68, 62, 84, 87, 98, 92, 95, 91};
/*
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
*/
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	radix_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
