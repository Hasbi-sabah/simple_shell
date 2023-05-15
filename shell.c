#include "head.h"

/**
 * check_ops - check code
 * @inputs: arguments set
 * @op: operation
 * Return: string
 */
char *check_ops(char **input, char *op)
{
	char *leftover, *temp;

	if ((leftover = strpbrk(*input, ";")))
	{
		temp = strdup(++leftover);
		*(--leftover) = '\0';
		while (*temp == ' ')
			temp++;
		return (temp);
	}
	else if ((leftover = strpbrk(*input, "&|")))
	{
		*op = leftover[0];
		temp = strdup(leftover + 2);
		*(leftover) = '\0';
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
	char op = 0;
	char *input, *temp, *leftover = NULL, *name = args[0], **arr;

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
			temp = strstr(input, "#");
			if (temp)
				*temp = '\0';
		}
		else if (input && *input != '\0')
			input = leftover;
		if (input && *input != '\0' && strcmp(input, "\n"))
		{
			leftover = check_ops(&input, &op);
			arr = _strtok(input, " \n");
			if (cmd_selector(arr[0], arr) == 0)
				_fork(name, arr);
		}
		free(input);
	}
	write(1, "\n", 1);
	return (0);
}
