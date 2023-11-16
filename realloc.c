#include "shell.h"

/**
 * _memset -It fills the memory with a constant byte.
 * @s: Pointer to the memory area.
 * @b: Byte to fill *s with.
 * @n: Amount of bytes to be filled.
 * Return: (s) a pointer to a memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - It frees the string of strings.
 * @pp: str of strs
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - It reallocates a block of a memory.
 * @ptr: Ptr to previous malloc allocated block.
 * @old_size: The byte size of the previous block.
 * @new_size: The byte size of a new block.
 *
 * Return: ptr to the ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
