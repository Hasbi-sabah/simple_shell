#include "head.h"

/**
 * replace_substring - check code
 * @str: input string
 * @old_substr: old substring
 * @new_substr: input substring
 * Return: command decomposition
 */
void replace_substring(char *str, char *old_substr, char *new_substr)
{
	char *ptr = _strstr(str, old_substr);
	size_t old_len = _strlen(old_substr);
	size_t new_len = _strlen(new_substr);
	int k = new_len, l = old_len;

	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l] != '\0');
	ptr[k] = '\0';
	_memcpy(ptr, new_substr, new_len);
	replace_substring(ptr + new_len, old_substr, new_substr);
}
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
	size_t k = 0, j = 0, i, len = _strlen(s);
	int found = 0;

	tokens = (char **)malloc(len * sizeof(char *));
	*tokens = (char *)malloc(len);
	for (i = 0; i < len; i++)
	{
		if (exists_within(s[i], delim))
		{
			if (s[i] == '\n')
			{
				tokens[k][j] = '\0';
				break;
			}
			if (found == 0 && tokens[k] != NULL)
				tokens[k++][j] = '\0';
			if (!tokens[k])
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
	while ((int)k >= 0 && _strlen(tokens[k]) == 0)
	{
		free(tokens[k]);
		tokens[k--] = NULL;
	}
	return (tokens);
}
/**
 * _atoi - convert a string to an integer
 *
 *@s: string
 * Return: integer
 */

int _atoi(char *s)
{
	int i, m;
	unsigned int n;

	for (i = 0, n = 0, m = 1; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			m = -m;
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				break;
		}
	}
	n *= m;
	return (n);
}
