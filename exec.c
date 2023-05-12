#include "head.h"

/**
 * execmd - execute
 * @arr: argument array
 * @name: name
 * Return: none
 */
void execmd(char **arr, char *name, char *path)
{
	char *comm = NULL, *env;

	(void) name;
	if (arr)
	{
		comm = arr[0];
		strcpy(arr[0], path);
		if (strstr(comm, "echo"))
		{
			env = getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				strcpy(arr[1], env);
			}
		}
		execve(comm, arr, environ);
	}
	_free(arr);
}
