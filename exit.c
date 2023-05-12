#include "head.h"

/**
 * exit_function - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void exit_function(int n, char **args)
{
	int i = 0;

	for (i = 0; !n && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			write(2, "Illegal number\n", 15);
			return;
		}
	}
	if (!n)
		i = atoi(args[1]);
	exit(i);
}
