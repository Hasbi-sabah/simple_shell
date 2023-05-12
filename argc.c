#include "head.h"
/**
 * args_count - check code
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (*args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
