#include "head.h"

/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int main(int argc, char **args)
{
	char *input, *name = args[0], **arr;

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
		arr = split_line(input);
		free(input);
		if (arr == NULL)
		{
			write(1, "\n", 1);
			continue;
		}
		printf("%d\n", args_count(arr));
		if (args_count(arr) > 0 && cmd_selector(arr[0], arr) == 0)
			_fork(name, arr);
	        _free(arr);
	}
	write(1, "\n", 1);
	return (0);
}
