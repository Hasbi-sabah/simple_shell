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
	aliases alias;
	int idx = 0;
	char *input, *name = args[0];

	(void) argc;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		if (_getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(1, "\n", 1);
			return (0);
		}
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			error(name, NULL, NULL, 0);
			split_line(input, name, &alias, &idx);
		}
		input = NULL;
	}
	write(1, "\n", 1);
	return (0);
}
