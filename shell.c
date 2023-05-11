#include "head.h"

/**
 * split_line - read command line
 * @input: input command line
 * Return: command decomposition
 */
char **split_line(char *input)
{
	char *input_cpy = NULL;

	input_cpy = malloc(strlen(input) + 1);
	if (!input_cpy)
		return (NULL);
	strcpy(input_cpy, input);
	return (_strtok(input_cpy, " \n"));
}
/**
 * main - simple shell program
 * @argc: arguments count
 * @args: arguments set
 * Return: 0
 */
int main(int argc, char **args)
{
	int flag;
	char *input, *name = args[0];

	(void) argc;

	while (1)
	{
		args = NULL;
		write(1, "$ ", 2);
		if (_getline(&input) <= 0)
		{
			free(input);
			write(1, "\n", 1);
			exit(0);
		}
		printf("-%s\n", input);
		flag = 0;
		if (strcmp(input, "\n") == 0)
			flag = 1;
		args = split_line(input);
		printf("-%s\n", args[0]);
		if (args == NULL)
			return (-1);
		if (strcmp(args[0], "exit") == 0)
			return (0);
		if (!flag)
			check_fork_error(args[0], args, name);
	}
	printf("\n");
	return (0);
}
