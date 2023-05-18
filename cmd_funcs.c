#include "head.h"

/**
 * exit_function - check code
 * @n: arguments count
 * @args: arguments
 * Return: success
 */
void exit_function(int n, char **args)
{
	int i;

	for (i = 0; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			_printf(2, "Illegal number: %s\n", args[1]);
			return;
		}
	}
	if (n > 1)
		i = atoi(args[1]);
	exit(i);
}

/**
 * change_dir - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
char *previous = NULL;
void change_dir(int argc, char **args)
{
	int r;
	char *path;
	static char *previous = NULL;

	if (!previous)
		getcwd(previous, 1024);
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	r = chdir(path);
	if (r < 0)
	{
		_printf(2, "cd: can't cd to %s\n", path);
		return;
	}
	getcwd(previous, 1024);
	setenv("PWD", path, 1);
}

/**
 * export - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void export(int argc, char **args)
{
	char **env;

	if (argc == 1)
		_printf(2, "setenv VARIABLE VALUE\n");
	else
	{
		env = _strtok(args[1], " =");
		setenv(env[0], env[1], 1);
	}
}

/**
 * unset - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void unset(int argc, char **args)
{
	if (argc == 1 || _getenv(args[1]) == NULL)
		_printf(1, "\n");
	else
		unsetenv(args[1]);
}

/**
 * env - prints env
 * @argc: argc
 * @args: arguments
 * Return: none
 */
void env(int argc, char **args)
{
	int i;

	(void) argc;
	(void) args;
	for (i = 0; environ[i]; i++)
		_printf(1, "%s\n", environ[i]);
}
