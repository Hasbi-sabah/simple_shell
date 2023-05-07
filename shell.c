#include "head.h"

/**
 * main - simple shell program
 * Return: 0
 */

int main(void)
{
	char *input = NULL, *input_cpy = NULL;
	char *delim = " \n", *token = NULL;
	char **arr;
	size_t n, i;

	while (1)
	{
		printf("$ ");
		n = getline(&input, &n, stdin);
		if ((int)n == -1)
		{
			printf("Shell has left the chat\n");
			return (-1);
		}
		input_cpy = malloc(sizeof(input));
		if (!input_cpy)
		{
			printf("Womp womp woomp, sorry, no can do!");
			return (-1);
		}
		strcpy(input_cpy, input);
		token = strtok(input_cpy, delim);
		for (n = 0; token; n++)
			token = strtok(NULL, delim);
		arr = malloc(sizeof(char *) * n);
		if (!arr)
		{
			printf("Womp womp woomp, sorry, no can do!");
			return (-1);
		}
		for (i = 0; i < n; i++)
		{
			if (!i)
				token = strtok(input, delim);
			else
				token = strtok(NULL, delim);
			arr[i] = malloc(sizeof(token));
			strcpy(arr[i], token);
		}
		arr[i] = NULL;
		execmd(arr);
	}
	printf("\n");
	return (0);
}
