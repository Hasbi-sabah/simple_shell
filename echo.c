#include "head.h"

/**
 * echo - check code
 * @argc: arguments count
 * @args: arguments
 * Return: success
 */
extern int EXIT_STATUS;
int echo(int argc, char **args)
{
	if (argc == 2)
	{
		if (strcmp(args[1], "$$"))
		{
			printf("%d\n", getpid());
			return (1);
		}
		else if (strcmp(args[1], "$?"))
		{
			printf("%d\n", WEXITSTATUS(EXIT_STATUS));
			return (1);
		}
	}
        return (0);
}
