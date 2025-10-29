#include "main.h"

/**
 * _atoi - convertit une chaîne en entier
 * @s: chaîne à convertir
 *
 * Return: entier correspondant à la chaîne
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0, found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (found)
			break;
		i++;
	}

	return (sign * num);
}
