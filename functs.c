#include "main.h"

/**
 * output_chars - prints a characters
 * @types: List a of arguements
 * @buffer: Buffer array to handle print function
 * @flags:  Calculates active flags
 * @width: Width of the array
 * @precision: Precision specs
 * @size: Size specs- fier
 * Return: Number of characters outputed
 */
int output_chars(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (deals_with_write_char(c, buffer, flags, width, precision, size));
}
/**
 * output_str - Outputs a string in theprog
 * @types: List a of args
 * @buffer: Buffer array to handle print function
 * @flags:  Gets active flags
 * @width: get width in the array in the progress
 * @precision: Precision specification
 * @size: Size specs-ier
 * Return: # of characters printed
 */
int output_str(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * output_percentages - Outputs a % sign
 * @types: Lists of args
 * @buffer: Buffer array to handle print function
 * @flags:  Gets active flags
 * @width: Gets width.
 * @precision: Precision specs
 * @size: Size specifier
 * Return: # of characters outputed
 */
int output_percentages(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Outputs integers inthe progress
 * @types: Lists all of args
 * @buffer: Buffer array to handle print function
 * @flags:  Getss active flags
 * @width: get width ot he prog
 * @precision: Precision specs
 * @size: Size specifier
 * Return: # of characters outputed
 */
int output_ints(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = changes_number_size(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (output_numbers(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * output_binaries - Outputs all unsigned #s
 * @types: Lists args
 * @buffer: Buffer array to handle print funtion
 * @flags:  Gets active flags
 * @width: gets width in the program
 * @precision: Precision specs
 * @size: Size specifier
 * Return: # of characters outputed
 */
int output_binaries(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
