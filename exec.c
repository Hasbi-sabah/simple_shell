#include "head.h"

/**
 * cmd_selector - check code
 * @cmd: command name
 * @args: arguments
 * Return: none
 */
int cmd_selector(const char *cmd, char **args)
{
	cmd_executer executers[] = {
		{"exit", exit_function},
		{"cd", change_dir},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exe_func != NULL && strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exe_func != NULL)
	{
		executers[j].exe_func(args_count(args), args);
		return (1);
	}
	return (0);
}
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
