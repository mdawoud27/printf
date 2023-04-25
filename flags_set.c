#include "main.h"

/**
 * set_flag - sets the corresponding flag in the flags_t struct based on the
 * flag specifier character found in the format string
 * @flag_specifier: the flag specifier character
 * @flags: a pointer to the flags_t struct to set the flag in
 *
 * Return: 1 if a flag has been set, 0 otherwise
 */
int set_flag(char flag_specifier, flags_t *flags)
{
	int flag_set = 0;

	switch (flag_specifier)
	{
		case '+':
			flags->plus = 1;
			flag_set = 1;
			break;
		case ' ':
			flags->space = 1;
			flag_set = 1;
			break;
		case '#':
			flags->hash = 1;
			flag_set = 1;
			break;
		case '-':
			flags->minus = 1;
			flag_set = 1;
			break;
	}

	return (flag_set);
}
