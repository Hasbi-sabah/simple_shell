#include "head.h"

/**
 * _strlen - swaps the values of two integers.
 *
 *@s: string
 * Return: length if string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - compares two strings
 *
 *@s1: first string
 *@s2: second string
 *
 *Return: integer
 */
int _strcmp(const char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}

/**
 * _strstr - locates a substring.
 *
 * @haystack: string
 * @needle: string looking for
 *
 * Return: location or NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*haystack == '\0' && *needle == '\0')
		return (NULL);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (needle[j] != haystack[i + j])
				break;
		}
		if (needle[j] == '\0')
			return (&haystack[i]);
	}
	return (NULL);
}
