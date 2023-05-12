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
	char *path;

	path = argc == 1 ? "~" : args[1];
	r = chdir(path);
	if (r < 0)
		perror("cd: %s: No such file or directory", path);
}
