#include "head.h"

/**
 * exit_function - check code
 * @n: arguments count
 * @args: arguments
 * @name: program name
 * Return: success
 */
void exit_function(int n, char **args, char *name)
{
	int i;

	for (i = 0; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			error(name, args, NULL, 2);
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
 * @name: program name
 * Return: none
 */
void change_dir(int argc, char **args, char *name)
{
	int r;
	char *path;
	static char *previous;

	if (!previous)
		getcwd(previous, 1024);
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	r = chdir(path);
	if (r < 0)
	{
		error(name, args, path, 3);
		return;
	}
	getcwd(previous, 1024);
	setenv("PWD", path, 1);
	if (argc == 1)
		_printf(1, "%s\n", path);
}
/**
 * export - check code
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * Return: none
 */
void export(int argc, char **args, char *name)
{
	char **env;

	if (argc == 1)
		error(name, args, NULL, 4);
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
 * @name: program name
 * Return: none
 */
void unset(int argc, char **args, char *name)
{
	if (argc == 1 || _getenv(args[1]) == NULL)
		error(name, args, NULL, 5);
	else
		unsetenv(args[1]);
}

/**
 * env - prints env
 * @argc: argc
 * @args: arguments
 * @name: program name
 * Return: none
 */
void env(int argc, char **args, char *name)
{
	int i;

	(void) argc;
	(void) args;
	(void) name;
	for (i = 0; environ[i]; i++)
		_printf(1, "%s\n", environ[i]);
}
