#include <unistd.h>

/**
 * _putchar - putchar string
 *  @c: char
 *
 */

void _putchar(char c)
{
	write(1, &c, 1);
}
