#include "head.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 *
 * @s: string
 * @accept: characters to accept
 *
 * Return: number or 0
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	if (*s == '\0' && *accept == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] != '\0')
			break;
	}
	if (s[i] != '\0')
		return (&s[i]);
	else
		return (0);
}
/**
 * _strcpy - copies the string pointed to by src to dest
 *
 *@src: string
 *@dest: buffer
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 * @str: string
 *
 * Return: pointer of NULL
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		p[i] = str[i];
	return (p);
	free(p);
}