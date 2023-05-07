#include "head.h"
/**
 * exits_within - check code
 * @c: character
 * @s: string
 * Return: boolean
 */
int exits_within(char c, char *s)
{
	int i;

	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
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
	size_t len = strlen(s);
	int i, j = 0, k = 0, found = 0;

	tokens = (char **)malloc(len * sizeof(char));
	*tokens = (char *)malloc(len * sizeof(char));
	for (i = 0; i < len; i++)
	{
		if (exists_within(s + i, delim))
		{
			if (found == 0)
			{
				tokens[k][++j] = '\0';
				k++;
			}
			tokens[k] = (char *)malloc(len * sizeof(char));
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	return (tokens);
}
