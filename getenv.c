#include "head.h"

/**
 * _getenv - check code
 * @var: variable name
 * Return: string
 */
char *_getenv(char *var)
{
	int i;
	char **temp;

	temp = malloc(sizeof(char *));
	for (i = 0; environ[i]; i++)
	{
		temp[0] = strdup(environ[i]);
		temp = _strtok(temp[0], "=");
		if (strcmp(var, temp[0]) == 0)
		{
			free(temp[0]);
			return (temp[1]);
		}
		free(temp[0]);
	}
	return (NULL);
}
