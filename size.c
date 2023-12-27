#include "main.h"

/**
 * secure_size - Enumerates the size to cast to the arg
 * @format: Formatted str to print the args
 * @i: List of args to be outputed
 * Return: The precision in the code
 */
int secure_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
