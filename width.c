#include "main.h"

/**
 * secure_width - enumerates the width to print
 * @format: Formatted str to print the args
 * @i: List of args to be lithoed
 * @list: The list of args
 * Return: The printed width
 */
int secure_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digits(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (width);
}
