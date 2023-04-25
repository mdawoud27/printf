#include "main.h"

/**
 * _print_str - prints a string
 * @str: pointer to the string to print
 * Return: number of characters written
 */
int _print_str(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		_print_char(*str);
		str++;
		len++;
	}

	return (len);
}
