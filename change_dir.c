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

	r = argc == 1 ? chdir("~") : chdir(args[1]);
	if (r < 0)
		perror("chdir() error");
}
