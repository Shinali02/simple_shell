#include "shell.h"

/**
 * _strlen - It returns the length of a str.
 * @s: A str whose length to check.
 *
 * Return: The integer length of a str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - It performs lexicogarphic comparison of the two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Always negative on success if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - It checks if the needle starts with haystack.
 * @haystack: The str to search.
 * @needle: The substr to find.
 *
 * Return: An address of the next character of haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - It concatenates two strs.
 * @dest: A destination buffer.
 * @src: A source buffer.
 *
 * Return: The pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
