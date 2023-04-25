#include "main.h"

/**
 * _print_str - prints a string
 * @str: pointer to the string to print
 * Return: number of characters written
 */
int _print_str(char *str)
{
<<<<<<< HEAD
	int len = 0;

	while (*str != '\0')
	{
		_print_char(*str);
		str++;
		len++;
	}

	return (len);
=======
int len = 0;

while (*str != '\0')
        {
           _print_char(*str);
           str++;
	   len++;
        }
	
        return (len);
>>>>>>> c778f7c5cc1d950751aa42c0ff7c417e103dfd49
}


