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
void _fork(char *name, char **arr)
{
	pid_t pid;
	int status;
	static int i = 0;
	char *path = NULL, *comm = NULL, *error, *i_str;

	i++;
	comm = arr[0];
	if ((path = is_valid(comm)))
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
	{
		i_str = malloc(20);
		i_str = int_to_str(i, i_str);
		error = malloc(strlen(i_str) + strlen(name) + strlen(comm) + strlen(": : : not found\n") + 4);
		strcpy(error, name), strcat(error, ": ");
		strcat(error, i_str), strcat(error, ": ");
		strcat(error, comm), strcat(error, ": not found\n");
		write(2, error, strlen(error));
		free(error);
		free(i_str);
	}
	free(path);
	free(comm);
}
char *int_to_str(int n, char *s)
{
	int i, j;
	char temp;

	for (i = 0; n > 0; i++, n /= 10)
		s[i] = n % 10 + '0';
	for (j = 0; j < i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = temp;
	}
	return (s);
}
