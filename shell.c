#include "head.h"

/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int main(int argc, char **args)
{
	char *input, *name = args[0];

	(void) argc;
	while (1)
	{
		write(1, "$ ", 2);
		if (_getline(&input) <= 0)
		{
			free(input);
			write(1, "\n", 1);
			return (0);
		}
		if (strcmp(input, "\n"))
		{
			args = NULL;
			args = split_line(input);
			free(input);
			if (args == NULL)
				return (-1);
			if (cmd_selector(args[0], args) == 0)
				_fork(name, args);
		}
	}
	write(1, "\n", 1);
	return (0);
}
