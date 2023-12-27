#include "main.h"

/**
 * print_unsigned - Outputs the allocated unsigned #
 * @types: List a of arguements in the function
 * @buffer: Buffer array to deal with print function
 * @flags:  Enumerates active flags
 * @width: secures  width in the function
 * @precision: The precision specs
 * @size: Size specs-fier
 * Return: The # of characters outputed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = changes_unsgnd_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (output_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * output_octal - Prints an unsigned # in octal notation
 * @types: Lists of arguements
 * @buffer: Buffer array to handle print funct in the code
 * block
 * @flags:  Computes active flags
 * @width: Aquires the width of a funct
 * @precision: Precision specs-fication
 * @size: Size specifier in the funct
 * Return: # of characters outputed
 */
int output_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = changes_unsgnd_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;
	return (output_unsigned(0, i, buffer, flags, width, precision, size));
}
/**
 * output_hexadecimal - Prints an unsigned # in hexadecimal notation
 * @types: Lists of arguements
 * @buffer: Buffer array to handle print functions
 * @flags:  Calculates active flags
 * @width: Enumerates width
 * @precision: Disntinctness specification
 * @size: Size specs-fier
 * Return: # of characters outputed
 */
int output_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexas(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * output_upper_hexa - Outputs an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int output_upper_hexa(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexas(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * output_hexas - Prints a hexadecimal #s in lower or upper
 * @types: Lists  arguements
 * @map_to: Array of values to map the # to
 * @buffer: Buffer array to handle print functs
 * @flags:  Computes active flags
 * @flag_ch: Computes active flags
 * @width: Secures width
 * @precision: Distinctiveness specs
 * @size: Size specs-fiers
 * @size: The # size specs
 * Return:  of characters printed
 */
int output_hexas(va_list types, char map_to[], char buffer[],
			int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = changes_unsgnd_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (output_unsigned(0, i, buffer, flags, width, precision, size));
}
