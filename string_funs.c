#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);
	int len = 0, i;

	(void)f;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	for (i = len - 1; i >= 0; i--)
		_print_char(s[i]);

	return (len);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 *
 * Return: number of characters printed
 */
int print_rot13(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);
	int len = 0;
	(void)f;

	if (s == NULL)
		s = "(null)";

	for (; *s != '\0'; s++)
	{
		if ((*s >= 'a' && *s <= 'm') || (*s >= 'A' && *s <= 'M'))
		{
			len += _print_char(*s + 13);
		}
		else if ((*s >= 'n' && *s <= 'z') || (*s >= 'N' && *s <= 'Z'))
		{
			len += _print_char(*s - 13);
		}
		else
		{
			len += _print_char(*s);
		}
	}

	return (len);
}

/**
 * print_S - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_S(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_print_str("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_print_str("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _print_char('0');
			count += _print_str(res);
		}
		else
			count += _print_char(s[i]);
	}
	return (count);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_print_char('%'));
}
