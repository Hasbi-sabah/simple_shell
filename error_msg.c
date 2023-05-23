#include "head.h"

/**
 * error - prints error msgs to stderr
 * @name: name
 * @args: args
 * @path: path
 * @n: error index
 */
int error(char *name, char **args, char *path, int n)
{
	static unsigned int i;

	if (!n)
	{
		i++;
		return (0);
	}
	print_string(2, name);
	print_string(2, ": ");
	to_string(2, i);
	print_string(2, ": ");
	if (n == 1)
	{
		print_string(2, args[0]);
		print_string(2, ": not found");
	}
	else if (n == 2)
	{
		print_string(2, "exit: Illegal number: ");
		print_string(2, args[1]);
	}
	else if (n == 3)
	{
		print_string(2, "cd: can't cd to ");
		print_string(2, path);
	}
	else if (n == 4)
		print_string(2, "usage: setenv VARIABLE VALUE");
	else if (n == 5)
		print_string(2, "usage: unsetenv VARIABLE VALUE");
	else if (n == 6)
	{
		print_string(2, "environment variable ");
		print_string(2, args[1]);
		print_string(2, " not found");
	}
	else if (n == 7)
		print_string(2, "Syntax error: \"&\" unexpected");
	else if (n == 8)
		print_string(2, "Syntax error: \"|\" unexpected");
	else if (n == 9)
		print_string(2, "Syntax error: \";;\" unexpected");
	else if (n == 10)
	{
		print_string(2, "alias: ");
		print_string(2, path);
		print_string(2, " not found");
	}
	write(2, "\n", 1);
	return (127);
}
