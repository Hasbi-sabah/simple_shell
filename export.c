#include "head.h"

/**
 * export - check code
 * @argc: arguments count
 * @args: arguments
 * Return: none
 */
void export(int argc, char **args)
{
	char **env;

	if (argc == 1)
	{
		for (env = environ; *env != NULL; env++)
			printf("%s=%s\n", *env, _getenv(*env));
	}
	else
	{
		env = _strtok(args[1], " =");
		setenv(env[0], env[1], 1);
	}
}
