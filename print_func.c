#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 *
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	int i;

	p_h func_arr[] = {
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_HEX},
		{'o', print_octal},
		{'b', print_binary},
		{'s', print_string},
		{'c', print_char},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_S},
		{'p', print_address},
		{'%', print_percent},
		{0, NULL}
	};

	for (i = 0; func_arr[i].ch != 0; i++)
	{
		if (func_arr[i].ch == s)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}
