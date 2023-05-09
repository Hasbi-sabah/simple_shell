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
 * @args: argument array
 */

void execmd(char **args)
{
	char *cmd = NULL;

	if (args)
	{
		cmd = args[0];
		if (execve(cmd, args, NULL) == -1)
			perror("Error");
	}
}
