#include "head.h"

/**
 * cmd_selector - check code
 * @cmd: command name
 * @va: variadic list
 * Return: none
 */
void cmd_selector(const char *cmd, va_list va)
{
	cmd_executer executers[] = {
		{"exit", NULL},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exe_func != NULL && strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exe_func != NULL)
		executers[j].exe_func(va);
}
/**
 * execmd - execute
 * @arr: argument array
 * @name: name
 * Return: none
 */
void execmd(char **arr, char *name)
{
	char *comm = NULL, *env, path[] = "/bin/";

	if (arr)
	{
		comm = arr[0];
		if (execve(comm, arr, environ) == -1)
		{
			if (is_command(comm))
			{
				strcat(path, comm);
				strcpy(comm, path);
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
			}
			if (execve(comm, arr, environ) == -1)
				perror(name);
		}
		else
			printf("%s: 1: %s: not found\n", name, comm);
	}
}
