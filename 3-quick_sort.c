#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - function for Quicksort
 * @array: array i need to sort
 * @izq: index of the left element
 * @der: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int izq, int der, size_t size)
{
	int piv;

	if (izq < der)
	{
		piv = part(array, izq, der, izq);
		quick_recursion(array, izq, piv - 1, size);
		quick_recursion(array, piv + 1, der, size);
	}
}

/**
 * part - gives a piv index for Quicksort
 * @array: array to find the piv in
 * @izq: index of the left element
 * @der: index of the right element
 * @size: size of the array
 *
 * Return: the index of the piv element
 */
int part(int *array, int izq, int der, size_t size)
{
	int tmp, i;
	int j;

	i = izq - 1;

	for (j = izq; j < der; j++)
	{
		if (array[j] < array[der])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[der] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[der];
		array[der] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
