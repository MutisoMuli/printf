#include "main.h"

void output_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the Printf function in th eprogram
 * @format: the format of the program.
 * Return: Printed chars in the program
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				output_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			output_buffer(buffer, &buff_ind);
			flags = secure_flags(format, &i);
			width = secure_width(format, &i, list);
			precision = secure_precision(format, &i, list);
			size = secure_size(format, &i);
			++i;
			printed = deals_with_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	output_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * output_buffer - Prints the conts of a present buffer
 * @buffer:  the array of chars
 * @buff_ind: Index at which to + next char, reps the length.
 */
void output_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
