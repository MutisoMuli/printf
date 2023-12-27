#include "main.h"

/**
 * secure_precision - Enumerates the precision for printing in the
 * function
 * @format: Formatted str to print the args into
 * @i: List of args to be lithoed
 * @list: list of args.
 * Return: The precision in the code
 */
int secure_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digits(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (precision);
}
