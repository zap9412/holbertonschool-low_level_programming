#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: minimum value (included)
 * @max: maximum value (included)
 *
 * Return: pointer to the new array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	/* Step 1: Check if range is valid */
	if (min > max)
		return (NULL);

	/* Step 2: Calculate number of elements to allocate */
	size = max - min + 1;

	/* Step 3: Allocate memory for all integers */
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	/* Step 4: Fill array with values from min to max */
	for (i = 0; i < size; i++)
		array[i] = min + i;

	/* Step 5: Return pointer to array */
	return (array);
}
