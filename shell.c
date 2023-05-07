#include "head.h"

/**
 * main - simple shell program
 * Return: 0
 */

int main(void)
{
	char *input = NULL, *input_cpy = NULL, *delim = " \n", *token = NULL, **args;
	size_t n, i;
	int argc;

	while (1)
	{
		printf("$ ");
		n = getline(&input, &n, stdin);
		if ((int)n == -1)
		{
			printf("Shell has left the chat\n");
			return (-1);
		}
		input_cpy = malloc(sizeof(char) * (strlen(input) + 1));
		if (!input_cpy)
		{
			printf("Womp womp woomp, sorry, no can do!");
			return (-1);
		}
		strcpy(input_cpy, input);
		argc = 0;
		do {
			token = strtok(argc == 0 ? input_cpy : NULL, delim);
			argc++;
		} while (token);
		argc++;
		args = malloc(sizeof(char *) * argc);
		if (!args)
		{
			printf("Womp womp woomp, sorry, no can do!");
			return (-1);
		}
		for (i = 0; i < argc; i++)
		{
			token = strtok(i == 0 ? input_cpy : NULL, delim);
			printf("%s ", token);
			args[i] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(args[i], token);
		}
		args[i] = NULL;
		execmd(args);
	}
	printf("\n");
	free(args);
	free(token);
	free(input_cpy);
	free(input);
	return (0);
}
