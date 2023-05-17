#include "head.h"

/**
 * change_dir - check code
 * @argc: arguments count
 * @args: arguments
 * Return: success
 */
char previous[1024];
int change_dir(int argc, char **args)
{
	int r;
	char *path;

	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	r = chdir(path);
	if (r < 0)
	{
		_printf("cd: %s: No such file or directory\n", path);
		return (1);
	}
	getcwd(previous, sizeof(previous));
	setenv("PWD", path, 1);
	return (1);
}
