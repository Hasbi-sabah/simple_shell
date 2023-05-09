#include "head.h"

/**
 * read_line - read command line
 * @input: input command line
 * Return: command decomposition
 */
char **read_line(char *input)
{
	char *input_cpy = NULL;

	input_cpy = malloc(sizeof(char) * (strlen(input) + 1));
	if (!input_cpy)
		return (NULL);
	strcpy(input_cpy, input);
	return (_strtok(input_cpy, " \n"));
}
/**
 * main - simple shell program
 * Return: 0
 */
int main(int argc, char **args)
{
	pid_t pid;
	int status;
	size_t n = 0;
	char *input = NULL, *name = args[0];

	(void) argc;

	while (1)
	{
		printf("$ ");
		if (args != NULL)
			args = NULL;
		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			return (0);
		}
		args = read_line(input);
		if (args == NULL)
			return (-1);
		if (strcmp(args[0], "exit") == 0)
			return (0);
		pid = fork();
		if (pid == 0)
		{
			execmd(args, name);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
	}
	printf("\n");
	free(args);
	return (0);
}
