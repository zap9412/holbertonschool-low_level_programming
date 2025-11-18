#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: the array of integers
 * @size: size of the array
 * @action: pointer to the function to use on each element
 *
 * This function goes through the array and applies 'action'
 * to every element (if action and array are not NULL).
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* safety checks to avoid crashing */
	if (array == NULL || action == NULL)
		return;

	/* loop through each element */
	for (i = 0; i < size; i++)
	{
		action(array[i]); /* call the function on the element */
	}
}
