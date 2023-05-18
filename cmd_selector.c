#include "head.h"

/**
 * cmd_selector - check code
 * @cmd: command name
 * @args: arguments
 * Return: success
 */
int cmd_selector(const char *cmd, char **args)
{
	cmd_executer executers[] = {
		{"exit", exit_function},
		{"cd", change_dir},
		{"setenv", export},
		{"unsetenv", unset},
		{"env", env},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exe_func != NULL && _strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exe_func != NULL)
	{
		executers[j].exe_func(args_count(args), args);
		return (1);
	}
	return (0);
}

/**
 * args_count - check code
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
