#include "head.h"

/**
 * change_dir - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void change_dir(int argc, char **args)
{
	int r;
	char *path, *error;
	static char *previous = NULL;

	if (!previous)
		getcwd(previous, 1024);
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	r = chdir(path);
	if (r < 0)
	{
		error = malloc(_strlen(path) + 4 + 29);
		_strcpy(error, "cd: ");
		_strcat(error, path);
		_strcat(error, ": No such file or directory\n");
		write(2, error, _strlen(error));
		free(error);
		return;
	}
	getcwd(previous, sizeof(previous));
	setenv("PWD", path, 1);
}
