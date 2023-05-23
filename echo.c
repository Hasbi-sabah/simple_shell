#include "head.h"

/**
 * echo - check code
 * @args: arguments
 * Return: success
 */
int echo(char **args)
{
	int status;

	if (!_strcmp(args[0], "echo") && args[1])
	{
		if (!_strcmp(args[1], "$$"))
		{
			to_string(1, getpid());
			write(1, "\n", 1);
			return (1);
		}
		else if (!_strcmp(args[1], "$?"))
		{
			waitpid(getpid() - 1, &status, 0);
			to_string(1, WEXITSTATUS(status));
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}
