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

	path = argc == 1 ? "~" : args[1];
	r = chdir(path);
	if (r < 0)
	{
		error = malloc(strlen(path) + 4 + 29);
		strcpy(error, "cd: ");
		strcat(error, path);
		strcat(error, ": No such file or directory\n");
		write(2, error, strlen(error));
		free(error);
	}
}
