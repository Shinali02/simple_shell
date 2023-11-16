#include "shell.h"

/**
 * bfree - It frees the pointer and NULLs the address.
 * @ptr: A pointer address to free.
 *
 * Return: Always 1 if freed (on success), otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
