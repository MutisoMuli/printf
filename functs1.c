#include "main.h"

/**
  * print_unsigned - Outputs the assigned unsigned number
  * @types: List of arguments in the function
  * @buffer: Buffer array for handling the print function
  * @flags: Enumerates active flags
  * @width: Ensures width in the function
  * @precision: Precision specifications
  * @size: Size specifier
  * Return: The number of characters outputted
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
  * output_octal - Prints an unsigned number in octal notation
  * @types: List of arguments
  * @buffer: Buffer array for handling print function in the code block
  * @flags: Computes active flags
  * @width: Acquires the width of a function
  * @precision: Precision specifications
  * @size: Size specifier in the function
  * Return: Number of characters outputted
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
  * output_hexadecimal - Prints an unsigned number in hexadecimal notation
  * @types: List of arguments
  * @buffer: Buffer array for handling print functions
  * @flags: Calculates active flags
  * @width: Enumerates width
  * @precision: Distinctness specification
  * @size: Size specifier
  * Return: Number of characters outputted
  */
int output_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexas(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
  * output_hexadecimal - Prints an unsigned number in hexadecimal notation
  * @types: List of arguments
  * @buffer: Buffer array for handling print functions
  * @flags: Calculates active flags
  * @width: Specifies the width
  * @precision: Distinctness specification
  * @size: Size specifier
  * Return: Number of characters outputted
  */
int output_upper_hexa(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexas(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
  * output_hexas - Prints a hexadecimal number in lower or upper case
  * @types: Lists arguments
  * @map_to: Array of values to map the number to
  * @buffer: Buffer array for handling print functions
  * @flags: Computes active flags
  * @flag_ch: Computes active flags
  * @width: Ensures width
  * @precision: Distinctiveness specifications
  * @size: Size specifications
  * Return: Number of characters printed
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
