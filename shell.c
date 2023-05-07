#include "head.h"

/**
 * read_line - read command line
 * @input: input command line
 * Return: command decomposition
 */
char **read_line(char *input)
{
	char *input_cpy = NULL;
	char *delim = " \n";

	input_cpy = malloc(sizeof(char) * (strlen(input) + 1));
	if (!input_cpy)
	{
		printf("Womp womp woomp, sorry, no can do!");
		return (NULL);
	}
	strcpy(input_cpy, input);
	return (_strtok(input_cpy, delim));
}
/**
 * main - simple shell program
 * Return: 0
 */
int main(void)
{
	char **args = NULL;
	pid_t pid;
	int status;
	size_t n = 0;
	char *input = NULL;

	while (1)
	{
		printf("$ ");
		if (args != NULL)
			free(args);
		if (getline(&input, &n, stdin) == -1)
		{
			printf("Shell has left the chat\n");
			free(input);
			return (0);
		}
		printf("no error");
		args = read_line(input);
		if (args == NULL)
			return (-1);
		pid = fork();
		if (pid == 0)
		{
			execmd(args);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
	}
	printf("\n");
	free(args);
	return (0);
}
