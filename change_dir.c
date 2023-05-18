#include "head.h"

/**
 * change_dir - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void change_dir(int argc, char **args)
{
	char *path;
	static char *previous = NULL;

	if (!previous)
		getcwd(previous, 1024);
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	if (chdir(path))
	{
		_printf(1, "cd: %s: No such file or directory\n", path);
		return;
	}
	getcwd(previous, 1024);
	setenv("PWD", path, 1);
}
