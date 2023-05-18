#include "head.h"

/**
 * check_ops - check code
 * @inputs: arguments set
 * @op: operation
 * Return: string
 */
char *check_ops(char **input)
{
	char *leftover, *temp;

	if ((leftover = _strpbrk(*input, ";")))
	{
		temp = _strdup(++leftover);
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
	char *input, *temp, *leftover = NULL, *name = args[0];

	(void) argc;
	while (1)
	{
		if (!leftover)
		{
			write(1, "$ ", 2);
			if (_getline(&input) <= 0)
			{
				write(1, "\n", 1);
				return (0);
			}
			temp = _strstr(input, "#");
			if (temp)
				*temp = '\0';
		}
		else
			input = leftover;
		
		if (_strcmp(input, "\n") && *input != '\0')
		{
			leftover = check_ops(&input);
			split_line(input, name);
		}
		free(input);
	}
	write(1, "\n", 1);
	return (0);
}
