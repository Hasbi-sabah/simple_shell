#include "head.h"

/**
 * execmd - execute
 * @arr: argument array
 * @name: name
 * @path: path
 * Return: none
 */
void execmd(char **arr, char *name, char *path)
{
	int i = 0;
	char *comm = NULL, *env;

	(void) name;
	if (arr)
	{
		comm = arr[0];
		if (!_strcmp(arr[0], "echo") && (i = echo(arr)) == 0 && arr[1][0] == '$')
		{
			env = _getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				_strcpy(arr[1], env);
			}
			else
			{
				write(1, "\n", 1);
				return;
			}
		}
		if (!i)
		{
			_strcpy(arr[0], path);
			execve(comm, arr, environ);
		}
	}
	_free(arr);
}
