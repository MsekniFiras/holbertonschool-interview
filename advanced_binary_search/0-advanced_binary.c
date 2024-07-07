#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - a function that searches for a value in a sorted array
 * @array: the array
 * @size: the number of elements in the array
 * @value: the value to search for
 * Return: index or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
    size_t i;
    int temp;

    if (array == NULL || size == 0)
        return (-1);

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        if (i == size - 1)
            printf("%d\n", array[i]);
        else
            printf("%d, ", array[i]);
    }

    size_t mid = (size - 1) / 2;

    if (array[mid] == value)
        return mid;

    if (array[mid] > value)
        return advanced_binary(array, mid, value);
    else
    {
        temp = advanced_binary(array + mid + 1, size - mid - 1, value);
        if (temp == -1)
            return -1;
        else
            return mid + 1 + temp;
    }

    return (-1);
}
