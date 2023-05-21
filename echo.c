#include "head.h"

/**
 * echo - check code
 * @argc: arguments count
 * @args: arguments
 * Return: success
 */
extern int EXIT_STATUS;
int echo(char **args)
{
	int status;

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
			waitpid(getpid() - 1, &status, 0);
		        to_string(1, WEXITSTATUS(status));
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}
