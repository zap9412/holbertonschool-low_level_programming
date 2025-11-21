#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

void print_char(va_list ap)
{
	char c = (char)va_arg(ap, int); /* char promu en int */
	printf("%c", c);
}

void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double)); /* float promu en double */
}

void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);
}

void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *sep = "";
	/* tableau d'associations : symbole -> fonction */
	printer_t funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(ap, format);
	if (format)
	{
		while (format[i])
		{
			j = 0;
			while (funcs[j].symbol)
			{
				if (format[i] == *(funcs[j].symbol))
				{
					printf("%s", sep);
					funcs[j].print(ap);
					sep = ", ";
					break;
				}
				j++;
			}
			i++;
		}
	}
	va_end(ap);
	printf("\n");
}
