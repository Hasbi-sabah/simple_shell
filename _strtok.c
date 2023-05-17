#include "head.h"

/**
 * exists_within - check code
 * @c: character
 * @s: string
 * Return: boolean
 */
int exists_within(char c, char *s)
{
	if (*s == '\0')
		return (c == *s);
	return (c == *s ? 1 : exists_within(c, s + 1));
}
/**
 * _strtok - check code
 * @s: string
 * @delim: string
 * Return: tokens set
 */
char **_strtok(char *s, char *delim)
{
	char **tokens;
	size_t k = 0, j = 0, i, len = strlen(s);
	int found = 0;

	tokens = (char **)malloc(len * sizeof(char *));
	*tokens = (char *)malloc(len);
	for (i = 0; i < len; i++)
	{
		if (exists_within(s[i], delim))
		{
		        if (s[i] == '\n')
				break;
			if (found == 0 && i > 0)
			{
				tokens[k][j] = '\0';
				k++;
			}
			tokens[k] = (char *)malloc(len);
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	while (_strlen(tokens[k]) == 0)
	{
		tokens[k] = NULL;
		k--;
	}
	return (tokens);
}
