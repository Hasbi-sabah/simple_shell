#include "head.h"

/**
 * execmd - execute
 * @arr: argument array
 */

void execmd(char **arr, char *name)
{
	char *comm = NULL;
	char *env;

	if (arr)
	{
		comm = arr[0];
		if (strstr(comm, "echo"))
		{
			env = getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				strcpy(arr[1], env);
			}
		}
		if (execve(comm, arr, environ) == -1)
			perror(name);
	}
}
