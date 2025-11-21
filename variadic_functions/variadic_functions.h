#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct printer - symbol to function mapping
 * @symbol: format symbol ("c", "i", "f", "s")
 * @print: function that prints the corresponding argument
 */
typedef struct printer
{
	char *symbol;
	void (*print)(va_list);
} printer_t;

void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
