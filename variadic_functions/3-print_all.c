#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct printer - mapping between a format symbol and a function
 * @symbol: the format symbol (string)
 * @print: function that prints the corresponding argument from va_list
 */
typedef struct printer
{
	char *symbol;
	void (*print)(va_list);
} printer_t;

/* helpers */
void print_char(va_list args)
{
	char c = (char) va_arg(args, int); /* char promoted to int */
	printf("%c", c);
}

void print_int(va_list args)
{
	int i = va_arg(args, int);
	printf("%d", i);
}

void print_float(va_list args)
{
	double f = va_arg(args, double); /* float promoted to double */
	printf("%f", f);
}

void print_string(va_list args)
{
	char *s = va_arg(args, char *);
	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);
}

/**
 * print_all - prints anything based on format string
 * @format: a string where each char indicates the type of the next arg:
 *          'c' -> char
 *          'i' -> integer
 *          'f' -> float
 *          's' -> char * (string)
 *
 * Description: Prints arguments separated by ", ". If a string is NULL,
 * prints "(nil)".
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *sep = "";

	/* array mapping format symbols to functions */
	printer_t funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			j = 0;
			while (funcs[j].symbol != NULL)
			{
				if (format[i] == *(funcs[j].symbol))
				{
					printf("%s", sep);
					funcs[j].print(args);
					sep = ", ";
					break;
				}
				j++;
			}
			i++;
		}
	}

	va_end(args);
	printf("\n");
}
