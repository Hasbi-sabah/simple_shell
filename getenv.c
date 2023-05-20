#include "head.h"

/**
 * _getenv - check code
 * @var: variable name
 * Return: string
 */
char *_getenv(char *var)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(var, environ[i], _strlen(var)))
		{
			temp = _strstr(environ[i], "=");
			temp++;
			return (temp);
		}
	}
	return (NULL);
}
/**
 * _getalias - checks for aliases
 * @aliases: aliases
 * @var: variable name
 * Return: string
 */
int _getalias(char **aliases, char *var, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!_strncmp(var, aliases[i], _strlen(var)))
			return (i);
	}
	return (-1);
}
