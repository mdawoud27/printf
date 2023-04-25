#include "main.h"

/**
 * convert - converts a number to a string in the given base
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * 
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num = num / base;
	} while (num);

	return (ptr);
}
