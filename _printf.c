#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * print_string - something usefull
 * @s: char
 * @z: int
 * Return: letter count
 */
int print_string(unsigned int z, char *s)
{
	int i = 0;

	if (!s)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		z = z + 6;
	}
	else
	{
		while (*(s + i) != '\0')
		{
			_putchar(*(s + i));
			i++;
			z++;
		}
	}
	return (z);
}
/**
 * print_char - something usefull
 * @c: char
 * @z: int
 * Return: letter count
 */
int print_char(unsigned int z, char c)
{
	_putchar(c);
	z++;
	return (z);
}
/**
 * print_decimal - This is decimal
 * @value: First operand
 * Return: 0 Successful
 */
int print_decimal(unsigned int r, int s)
{
	int mod = 0, c = 0;
	unsigned int n;
	char eded[11];

	if (s < 0)
	{
		_putchar('-');
		r++;
		n = -1 * s;
	}
	else
		n = s;
	if (n == 0)
	{
		_putchar(48);
		return (r + 1);
	}
	while (n > 0)
	{
		mod = n % 10;
		eded[c] = mod + 48;
		n = n / 10;
		c++;
	}
	r = r + c;
	c = c - 1;
	while (c >= 0)
	{
		_putchar(eded[c]);
		c--;
	}
	return (r);
}
	
/**
 * _printf - print string
 * @format: format
 * Return: letter count
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	unsigned int j = 0, r = 0;

	if (format == NULL)
		exit(98);
	va_start(ptr, format);
	for (j = 0; *(format + j) != '\0'; j++)
	{
		if (*(format + j) != '%')
		{
			r++, _putchar(*(format + j)); }
		else if (*(format + j) == '%' && *(format + j + 1) == '\0')
			continue;
		else if (*(format + j) == '%' && *(format + j + 1) == '%')
		{
			r++, j++, _putchar('%'); }
		else if (*(format + j) == '%' && *(format + j + 1) == 'c')
		{
			r = print_char(r, va_arg(ptr, int));
			j++; }
		else if (*(format + j) == '%' && *(format + j + 1) == 's')
		{
			r = print_string(r, va_arg(ptr, char *));
			j++; }
		else if ((*(format + j) == '%') && ((*(format + j + 1) == 'd')
			 || (*(format + j + 1) == 'i')))
		{
			r = print_decimal(r, va_arg(ptr, int));
			j++; }
		else
			r++, _putchar(*(format + j));
	}
	if (r == 0)
		r = -1;
	return (r); }
