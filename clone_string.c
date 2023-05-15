#include "head.h"

/**
 * clone - check code
 * @s: string to clone
 * Return: string
 */
char *clone(char *s)
{
	char *clone;

	if (s == NULL)
		return (NULL);
	clone = malloc(1 + strlen(s));
	strcpy(clone, s);
	return (clone);
}
