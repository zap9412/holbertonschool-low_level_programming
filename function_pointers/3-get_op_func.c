#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function for the operator
 * @s: operator string
 *
 * Return: pointer to the corresponding function, or NULL if not found
 *
 * Constraints respected:
 * - only the variables `ops` and `i` are declared here
 * - uses a single while loop (no for/do...while)
 * - does not use switch/else/goto
 * - uses at most one if (implicit in returning)
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	/* single while to search the table */
	while (ops[i].op != NULL && strcmp(ops[i].op, s) != 0)
		i++;

	/* if we reached the end ops[i].op == NULL -> ops[i].f is NULL */
	return (ops[i].f);
}
