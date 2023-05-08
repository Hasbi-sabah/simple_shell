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
	{
		printf("Womp womp woomp, sorry, no can do!");
		return (NULL);
	}
	strcpy(input_cpy, input);
	return (_strtok(input_cpy, " \n"));
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
		args = split_line(input);
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
