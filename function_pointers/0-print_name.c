#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - calls a provided function to print a name
 * @name: the name to print
 * @f: pointer to a function that takes a char * and returns void
 *
 * The function simply delegates the printing to 'f' if 'f' is not NULL.
 * We do not alter the name; we only ensure we don't call through a NULL
 * function pointer which would crash the program.
 */
void print_name(char *name, void (*f)(char *))
{
	/* If no function was provided, do nothing (avoid a crash). */
	if (f == NULL)
		return;

	/* Call the function provided by the caller, passing the name. */
	f(name);
}
