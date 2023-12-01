#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - print
 * @ptr: parametr
 * @len: lenght
 *
 *
 */

void print_string(va_list ptr, int *len)
{
	int el = 0;
	char *str = va_arg(ptr, char*);

	if (str == NULL)
	{
		(*len) += write(1, "(null)", 6);
	}
	else
	{
		while (str[el])
		{
			el++;
		}
		write(1, str, el);
		(*len) += el;
	}
}
