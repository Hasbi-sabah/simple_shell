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
	char *path, *error;

	path = argc == 1 || strcmp(args[1], "~") == 0 ? getenv("HOME") : args[1];
	if (strcmp(path, "-") == 0)
		path = previous;
	r = chdir(path);
	if (r < 0)
	{
		error = malloc(strlen(path) + 4 + 29);
		strcpy(error, "cd: ");
		strcat(error, path);
		strcat(error, ": No such file or directory\n");
		write(2, error, strlen(error));
		free(error);
		return;
	}
	getcwd(previous, sizeof(previous));
	setenv("PWD", path, 1);
}
