#include "shell.h"

/**
 * Interactive - Returns true if shell is in interactive mode.
 * @info: Struct address.
 *
 * Return: 1(Always Success) if interactive mode is 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it checks if the character is a delimeter.
 * @c: A character to check.
 * @delim: A delimeter str
 * Return: 1(Always Success) if true, 0 if false.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for the alphabetic char.
 * @c: A char to input.
 * Return: 1(Always Success) if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - It converts a str to an integer.
 * @s: A str to be converted.
 * Return: Always 0(Success) if no numbers in a str, converted number otherwise.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
