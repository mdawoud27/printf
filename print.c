#include "main.h"

/**
 * print_string - prints a string
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);
	int count = 0;

	(void)f;

	if (!s)
		s = "(null)";

	while (*s != '\0')
	{
		count += _print_char(*s);
		s++;
	}

	return (count);
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_print_char(va_arg(l, int));
	return (1);
}
