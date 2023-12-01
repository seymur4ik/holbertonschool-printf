#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - print
 * @format: list arguments
 *
 *
 * Return: len
 */

int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list ptr;

	va_start(ptr, format);
	if (!format)
		exit(98);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				print_char(ptr, &len);
			else if (format[i + 1] == 's')
				print_string(ptr, &len);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				len+=print_decimal(va_arg(ptr, int));
				len++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				len++;
			}
			else if (format[i + 1] == '\0')
				continue;
			else
			{
				_putchar('%');
				_putchar(format[i + 1]);
				len += 2;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	if (len == 0)
		return (-1);
	va_end(ptr);
	return (len);
}
