#include "head.h"

/**
 * check_ops - check code
 * @inputs: arguments set
 * Return: string
 */
char *check_ops(char **input)
{
	char *leftover, *temp;

	leftover = strpbrk(*input, ";");
	if (leftover)
	{
		temp = strdup(++leftover);
		*(--leftover) = '\0';
		while (*temp == ' ')
			temp++;
		return (temp);
	}
	return (NULL);
}
/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int EXIT_STATUS = 0;
int ERROR_ID = 0;
int main(int argc, char **args)
{
	char *input, *leftover = NULL, *name = args[0], **arr;

	(void) argc;
	while (1)
	{
		if (!leftover)
		{
			write(1, "$ ", 2);
			if (_getline(&input) <= 0)
			{
				free(input);
				write(1, "\n", 1);
				return (0);
			}
		}
		else
			input = leftover;
		if (strcmp(input, "\n"))
		{
			leftover = check_ops(&input);
			arr = _strtok(input, " \n");
			if (args_count(arr) > 0 && cmd_selector(arr[0], arr) == 0)
				_fork(name, arr);
		}
	}
	write(1, "\n", 1);
	return (0);
}
