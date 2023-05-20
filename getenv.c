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
int _getalias(aliases *alias, char *var, int idx, int flag)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (flag && !_strcmp(var, alias[i].name))
			return (i);
		if (!flag && !_strcmp(var, alias[i].value))
			return (i);
	}
	return (-1);
}
