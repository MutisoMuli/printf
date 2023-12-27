#include "main.h"

/**
 * is_printable - Checks if a char in the prog' is printable
 * @c: The char int he prog to be evalauted
 * Return: retunr 1 if char is printable or 0 if not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * adds_hexacodes - Adds ascci in hexadecimal code to buffer
 * @buffer: Array of chars in the program
 * @i: Index at which to start adding ascci in hexadecimal
 * format
 * @ascii_code: ASSCI CODE
 * Return: Always three (3)
 */
int adds_hexacodes(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digits - Makes sure char is a digit
 * @c: Char to be evaluated in the program
 * Return: 1 if char is a digit and zero(0) if not
 */
int is_digits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * changes_number_size - Casts a # to the specified size
 * @num: # to be casted.
 * @size: The # indicating the type to be casted.
 * Return: Casted value of num in the program
 */
long int changes_number_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * changes_unsgnd_size - Casts a # to the specified size
 * @num: The # to be casted
 * @size: The # indicating the type to be casted
 * Return: Casted value of num in the program
 */
long int changes_unsgnd_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
