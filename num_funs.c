#include "main.h"

/**
 * count_digit - counts the number of digits in an integer
 * @i: the integer to count digits of
 *
 * Return: the number of digits in the integer
 */
int count_digit(int i)
{
	int digits = 0;
	unsigned int u = (i < 0) ? -i : i;

	do {
		digits++;
		u /= 10;
	} while (u != 0);

	return (digits);
}

/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);
	int is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	if (f->space == 1 && f->plus == 0 && !is_negative)
		res += _print_char(' ');

	if (f->plus == 1 && !is_negative)
		res += _print_char('+');

	if (is_negative)
		res += _print_char('-');

	print_number(n);

	return (res);
}

/**
 * print_number - fun printes int
 * @n: an integer number
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_print_char('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_print_char((n1 % 10) + '0');
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char buf[21];  /*buffer for storing the converted number*/
	char *p = buf + 20;  /*pointer to the end of the buffer*/
	int count = 0;

	(void)f;

	/**
	 * Convert the number to a string and store it in
	 * the buffer in reverse order
	 */
	*p = '\0';
	do {
		*--p = (char) ('0' + u % 10);
		u /= 10;
	} while (u != 0);

	/*Print the string*/
	while (*p != '\0')
	{
		count += _print_char(*p++);
	}

	return (count);
}
