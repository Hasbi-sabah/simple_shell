#include "head.h"

/**
 * error - prints error msgs to stderr
 * @name: name
 * @args: args
 * @path: path
 * @n: error index
 */
void error(char *name, char **args, char *path, int n)
{
	static int i;

	i++;
	if (n == 1)
		_printf(2, "%s: %i: %s: not found\n", name, i, args[0]);
	else if (n == 2)
		_printf(2, "%s: %i: exit: Illegal number: %s\n", name, i, args[1]);
	else if (n == 3)
		_printf(2, "%s: %i: cd: can't cd to %s\n", name, --i, path);
	else if (n == 4)
		_printf(2, "%s: %i: usage: setenv VARIABLE VALUE\n", name, --i);
	else if (n == 5)
		_printf(2, "%s: %i: usage: unsetenv VARIABLE\n", name, --i);
	else if (n == 6)
	{
		_printf(2, "%s: %i: environment variable ", name, --i);
		_printf(2, "%s not found\n", args[1]);
	}
}
