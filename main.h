#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int deals_with_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int output_chars(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_str(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_percentages(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int output_ints(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_binaries(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int output_upper_hexa(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int output_hexas(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int output_nonprintables(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Funcion to print memory address */
int output_pointers(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int secure_flags(const char *format, int *i);
int secure_width(const char *format, int *i, va_list list);
int secure_precision(const char *format, int *i, va_list list);
int secure_size(const char *format, int *i);

/*Function to print string in reverse*/
int output_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int output_rotate_str(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int deals_with_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int output_numbers(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int writes_nums(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int writes_pointers(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);

int output_unsigned(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int adds_hexacodes(char, char[], int);
int is_digits(char);

long int changes_number_size(long int num, int size);
long int changes_unsgnd_size(unsigned long int num, int size);

#endif /* MAIN_H */
