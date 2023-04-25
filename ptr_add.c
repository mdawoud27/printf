#include "main.h"

/**
 * print_address - prints the address of the input in hexadecimal format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 *     if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
	unsigned long int addr = va_arg(l, unsigned long int);
	char *hex = convert(addr, 16, 1);
	int count = 0;

	(void)f;

	if (addr == 0)
		return (_print_str("(nil)"));

	count += _print_str("0x");
	count += _print_str(hex);

	return (count);
}
