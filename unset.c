#include "head.h"

/**
 * unset - check code
 * @argc: arguments count
 * @args: arguments
 * Return: success
 */
int unset(int argc, char **args)
{
        if (argc == 1 || getenv(args[1]) == NULL)
		write(1, "\n", 1);
	else
		unsetenv(args[1]);
}
