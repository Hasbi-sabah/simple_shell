#include "head.h"

/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int EXIT_STATUS = 0;
int main(int argc, char **args)
{
	char *input, *name = args[0];

	(void) argc;
	while (1)
	{
		_printf(1, "$ ");
		if (_getline(&input) <= 0)
		{
			free(input);
			write(1, "\n", 1);
			return (0);
		}
		if (_strcmp(input, "\n") && *input != '\0')
		{
			error(name, NULL, NULL, 0);
			split_line(input, name);
		}
	}
	_printf(1, "\n");
	return (0);
}
