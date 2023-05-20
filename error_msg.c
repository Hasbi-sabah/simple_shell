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
	static unsigned int i = 0;

	if (n < 10)
	{
		print_string(name);
		print_string(": ");
		to_string(i);
		print_string(": ");
	}
	if (n == 1)
	{
		print_string(args[0]);
		print_string(": not found");
	}
	else if (n == 2)
	{
		print_string("exit: Illegal number: ");
		print_string(args[1]);
	}
	else if (n == 3)
	{
		print_string("cd: can't cd to ");
		print_string(path);
	}
	else if (n == 4)
		print_string("usage: setenv VARIABLE VALUE");
	else if (n == 5)
		print_string("usage: unsetenv VARIABLE VALUE");
	else if (n == 6)
	{
		print_string("environment variable ");
		print_string(args[1]);
		print_string(" not found");
	}
	else if (n == 7)
		print_string("Syntax error: \"&\" unexpected");
	else if (n == 8)
		print_string("Syntax error: \"|\" unexpected");
	else if (n == 9)
		print_string("Syntax error: \";;\" unexpected");
	else if (n == 10)
	{
		print_string("alias: ");
		print_string(path);
		print_string(" not found");
	}
        write(1, "\n", 1);
        i++;
}
