#include "head.h"
/**
 * args_count - check code
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (*args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
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
		if (path)
		{
			strcat(path, "/");
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
		execve(comm, arr, environ);
	}
	_free(arr);
}
void _fork(char *name, char **arr)
{
	pid_t pid;
	int status;
	char *path = NULL, *comm = NULL;

	comm = arr[0];
	if (is_path(comm) || (path = is_command(comm)))
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
		printf("error\n");
	free(path);
	free(comm);
}
