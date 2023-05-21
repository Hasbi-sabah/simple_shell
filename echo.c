#include "head.h"

/**
 * echo - check code
 * @argc: arguments count
 * @args: arguments
 * Return: success
 */
int echo(char **args)
{
	if (args[1])
	{
		if (!_strcmp(args[1], "$$"))
		{
			to_string(1, getpid());
			write(1, "\n", 1);
			return (1);
		}
		else if (!_strcmp(args[1], "$?"))
		{
			to_string(1, WEXITSTATUS(EXIT_STATUS));
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}
