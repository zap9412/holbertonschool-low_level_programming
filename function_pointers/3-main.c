#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point for the calculator program
 * Usage: calc num1 operator num2
 *
 * Exits with:
 *  98 on wrong argument count
 *  99 on invalid operator
 * 100 on division or modulo by 0
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*op_func)(int, int);

	/* 1) check number of arguments (1 if statement) */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* 2) get the function for the operator */
	op_func = get_op_func(argv[2]);

	/* 3) operator validity check (2nd if statement) */
	if (op_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* 4) convert operands */
	a = atoi(argv[1]);
	b = atoi(argv[3]);

	/* 5) division/modulo by zero check (3rd if statement) */
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* 6) perform operation via function pointer (no direct calls) */
	result = op_func(a, b);
	printf("%d\n", result);
	return (0);
}
