#include "main.h"

/**
 * _print_char - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_char(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1023)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != -1)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}
