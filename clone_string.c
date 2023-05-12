#include "head.h"

/**
 * clone - check code
 * @s: string to clone
 * Return: string
 */
char *clone(char *s)
{
	char *clone = malloc(1 + strlen(s));

	if (s == NULL)
		return (NULL);
	strcpy(clone, s);
	return (clone);
}
