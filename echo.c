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
	if (args[1])
	{
		if (!_strcmp(args[1], "$$"))
		{
			_printf(1, "%d\n", getpid());
			return (1);
		}
		else if (!_strcmp(args[1], "$?"))
		{
			_printf(1, "%d\n", WEXITSTATUS(EXIT_STATUS));
			return (1);
		}
	}
	return (0);
}
