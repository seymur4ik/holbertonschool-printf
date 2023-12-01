#include <stdarg.h>
#include "main.h"

/**
 * print_char - print char
 * @ptr: argument
 * @len: size
 *
 * Return:
 *
 */

void print_char(va_list ptr, int *len)
{
	_putchar(va_arg(ptr, int));
	(*len)++;
}
