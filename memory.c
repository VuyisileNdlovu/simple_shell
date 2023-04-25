#include "shell.h"

/**
 * bfree - frees a pointer and sets its address to NULL
 * @ptr: pointer to free
 *
 * Return: 1 on success, otherwise 0.
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
