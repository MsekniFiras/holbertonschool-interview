#include "sort.h"
/**
 * merge - merge two arraies
 * @array: array to sort
 * @copy: a copy of the array to sort
 * @start: start index
 * @end:  end index
 * @mid: mid index
 */
void merge(int *array, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int i = 0;

	for (i = start; i < end; i++)
	{

		if (s < mid && (m >= end || copy[s] <= copy[m]))
		{
			array[i] = copy[s];
			s = s + 1;
		}
		else
		{
			array[i] = copy[m];
			m = m + 1;
		}
	}
}
/**
 *split - split  array
 *@array: array to sort
 *@sorted_array: a copy of the array to sort
 *@firsthalf: start index of the array
 *@secondehalf: end index of the array
 */
void split(int *array, int firsthalf, int secondehalf, int *sorted_array)
{
	int mid = (firsthalf + secondehalf) / 2;
	int i = 0;

	if (secondehalf - firsthalf <= 1)
		return;

	split(sorted_array, firsthalf, mid, array);
	split(sorted_array, mid, secondehalf, array);
	printf("Merging...\n");

	printf("[left]: ");
	for (i = firsthalf; i < mid; i++)
	{
		printf("%d", sorted_array[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (i = mid; i < secondehalf; i++)
	{
		printf("%d", sorted_array[i]);
		if (i < secondehalf - 1)
			printf(", ");
	}

	merge(array, firsthalf, mid, secondehalf, sorted_array);

	printf("\n");
	printf("[Done]: ");
	for (i = firsthalf; i < secondehalf; i++)
	{
		printf("%d", array[i]);
		if (i < secondehalf - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge_sort -  sort array using merge sort
 * @array: array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t a = 0;

	copy = malloc(sizeof(int) * size);

	for (a = 0; a < size; a++)
		copy[a] = array[a];

	split(array, 0, size, copy);
	free(copy);
}
