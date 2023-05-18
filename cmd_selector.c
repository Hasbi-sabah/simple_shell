#include "head.h"

/**
 * cmd_selector - check code
 * @cmd: command name
 * @args: arguments
 * @name: program name
 * Return: success
 */
int cmd_selector(const char *cmd, char **args, char *name)
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
		error(name, args, NULL, 0);
		executers[j].exe_func(args_count(args), args, name);
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
