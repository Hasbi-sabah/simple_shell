#include "head.h"

/**
 * is_valid - is valid command
 * @comm: command
 * Return: string
 */
char *is_valid(char *comm)
{
	int i;
	struct stat buf;
	char *path, **path_arr, *env;

	env = _getenv("PATH");
	path_arr = _strtok(env, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (!_strstr(comm, "/"))
		{
			path = malloc(_strlen(path_arr[i]) + _strlen(comm) + 2);
			_strcpy(path, path_arr[i]);
			_strcat(path, "/");
			_strcat(path, comm);
		}
		else
		{
			path = malloc(_strlen(comm) + 1);
			_strcpy(path, comm);
		}
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			_free(path_arr);
			return (path);
		}

	}
	_free(path_arr);
	return (NULL);
}
