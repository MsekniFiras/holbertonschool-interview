#include "search_algos.h"

/**
 * advanced_binary - a function that searches for a value in an array
 * @array: the array
 * @size: the number of elements in the array
 * @value: the value to search for
 * Return: index or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t i, h, idx = 0;
	int temp;
	if (array == NULL)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (size == 1 && array[0] != value)
		return (-1);
	h = (size - 1) / 2;
	if (array[h] == value)
	{
		if (array[h - 1] < value)
		return (h);
	}
	if (array[h] < value)
	{
		idx += h + 1;
		array += h + 1;
		if (size % 2 != 0)
			h--;
	}
	h++;
	temp = advanced_binary(array, h, value);
	if (temp != -1)
		return (temp + idx);
	return (-1);
}
