#include "main.h"
/**
  * deals_with_print - Prints arguments depending on their types
  * @fmt: Formatted string to print the arguments into
  * @list: List of arguments to be printed
  * @ind: The index
  * @buffer: Buffer array for handling print functions
  * @flags: Enumerates active flags
  * @width: Ensures the width
  * @precision: Precision specifications
  * @size: Size specifier
  * Return: Either 1 or 2
  */

int deals_with_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', output_chars}, {'s', output_str}, {'%', output_percentages},
		{'i', output_ints}, {'d', output_ints}, {'b', output_binaries},
		{'u', print_unsigned}, {'o', output_octal}, {'x', output_hexadecimal},
		{'X', output_upper_hexa}, {'p', output_pointers},
		{'S', output_nonprintables},
		{'r', output_reverse}, {'R', output_rotate_str}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
