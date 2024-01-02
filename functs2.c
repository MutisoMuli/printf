#include "main.h"

/**
  * output_pointers - Prints the value pointed to by a pointer variable
  * @types: List of arguments
  * @buffer: Buffer array for handling print functions
  * @flags: Computes active flags
  * @width: Ensures the width
  * @precision: Precision specifications
  * @size: Size specifier in the code
  * Return: The number of characters outputted
  */
int output_pointers(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (writes_pointers(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/**
  * output_nonprintables - Displays the ASCII codes in
  * hexadecimal of non-printable characters
  * @types: List of arguments
  * @buffer: Buffer array for handling print functions
  * @flags: Enumerates dynamic flags
  * @width: Ensures the width
  * @precision: Precision specifications
  * @size: Size specifier
  * Return: The number of characters displayed
  */
int output_nonprintables(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += adds_hexacodes(str[i], buffer, i + offset);

		i++;
	}
	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
  * output_reverse - Outputs a string in reverse format
  * @types: List of arguments
  * @buffer: Buffer array for handling print functionalities
  * @flags: Determines active flags
  * @width: Ensures the width
  * @precision: Precision specifications
  * @size: Size specifier
  * Return: The number of characters outputted
  */
int output_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
  * output_rotate_str - Prints a string in rot13.
  * @types: List of arguments
  * @buffer: Buffer array for handling print functionalities
  * @flags: Enumerates dynamic flags
  * @width: Gets the width
  * @precision: Precision specifications
  * @size: Size specifier
  * Return: The number of characters printed
  */
int output_rotate_str(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
