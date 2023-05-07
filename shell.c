#include "head.h"

/**
 * read_line - read command line
 * Return: command decomposition
 */
char **read_line(void)
{
	size_t len;
	int argc, i;
	char *input = NULL, *input_cpy = NULL;
	char *delim = " \n", *token = NULL, **args = NULL;

	getline(&input, &len, stdin);
	if (len == 0)
	{
		printf("Shell has left the chat\n");
		return (NULL);
	}
	input_cpy = malloc(sizeof(char) * (strlen(input) + 1));
	if (!input_cpy)
	{
		printf("Womp womp woomp, sorry, no can do!");
		return (NULL);
	}
	strcpy(input_cpy, input);
	free(input);
	argc = 0;
	do {
		token = strtok(argc == 0 ? input_cpy : NULL, delim);
		argc++;
	} while (token);
	args = malloc(sizeof(char *) * (1 + argc));
	if (args == NULL)
	{
		printf("Womp womp woomp, sorry, no can do!");
		return (NULL);
	}
	for (i = 0; i < argc; i++)
	{
		token = strtok(i == 0 ? input_cpy : NULL, delim);
		printf("%s ", token);
		args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(args[i], token);
	}
	args[i] = NULL;
	free(input_cpy);
}
/**
 * main - simple shell program
 * Return: 0
 */
int main(void)
{
	char **args = NULL;

	while (1)
	{
		printf("$ ");
		if (args != NULL)
			free(args);
		args = read_line();
		if (args == NULL)
			return (-1);
		execmd(args);
	}
	printf("\n");
	free(args);
	return (0);
}
