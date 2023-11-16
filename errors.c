#include "shell.h"

/**
 * _eputs - prints the input string
 * @str: The string to be printed from.
 *
 * Return: Nothing
 *
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the char c to stderr.
 * @c: The char to print.
 *
 * Return: Always 1(Success), on error, -1 is returned and error num is set appropriately.
 *
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the char c to a given fd.
 * @c: A chars to print.
 * @fd: A file descriptor to write to.
 *
 * Return: Always 1(Success), on error, -1 is returned and error num is set appropriately.
 *
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints the input string.
 * @str: A string to be printed.
 * @fd: A file descriptor to write to.
 *
 * Return: The num of characters added.
 *
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
