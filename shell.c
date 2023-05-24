#include "head.h"

/**
 * _read - reads file
 * @line: holder
 * @args: source
 * Return: int
 */
int _read(char **line, char **args)
{
	ssize_t i;
	int ret;

	ret = open(args[1], O_RDONLY);
	if (ret == -1)
	{
		error(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*line = malloc(10240);
	i = read(ret, *line, 10240);
	close(ret);
	while (**line == ' ' || **line == '\t')
		(*line)++, i--;
	(*line)[i] = '\0';
	return (i);
}
/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int main(int argc, char **args)
{
	aliases alias;
	int idx = 0, ret_val = 0;
	char *input, *name = args[0];

	(void) argc;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0) && argc == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (argc == 1 && _getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else if (argc != 1 && _read(&input, args) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			error(name, NULL, NULL, 0);
			ret_val = split_line(input, name, &alias, &idx);
		}
		free(input);
		if (argc != 1)
			return (0);
	}
}
