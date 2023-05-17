#include "head.h"

/**
 * exit_function - check code
 * @n: arguments count
 * @args: arguments
 * Return: success
 */
void exit_function(int n, char **args)
{
	int i;

	for (i = 0; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			write(2, "Illegal number\n", 15);
			return;
		}
	}
	if (n > 1)
		i = atoi(args[1]);
	exit(i);
}
