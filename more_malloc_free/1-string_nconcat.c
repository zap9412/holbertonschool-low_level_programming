#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates s1 and first n bytes of s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated concatenated string
 *         NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1, len2, total_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
		n = len2;

	total_len = len1 + n + 1;  /* +1 for '\0' */

	new_str = malloc(total_len);
	if (!new_str)
		return (NULL);

	/* Copy s1 */
	memcpy(new_str, s1, len1);
	/* Copy first n bytes of s2 */
	memcpy(new_str + len1, s2, n);
	/* Null terminate */
	new_str[len1 + n] = '\0';

	return (new_str);
}
