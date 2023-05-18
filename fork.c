#include "head.h"

/**
 * _fork - check code
 * @name: command name
 * @arr: arguments
 * Return: none
 */
void _fork(char *name, char **arr)
{
	pid_t pid;
	static int i;
	int status;
	char *path = NULL, *comm = NULL;

	i++;
	comm = arr[0];
	path = is_valid(comm);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			execmd(arr, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
	}
	else
		_printf(2, "%s: %i: %s: not found\n", name, i, comm);
}
