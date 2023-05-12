#include "head.h"

/**
 * split_line - read command line
 * @input: input command line
 * Return: command decomposition
 */
char **split_line(char *input)
{
	char *input_cpy = NULL;

	if (input == NULL || strlen(input))
		return (NULL);
	input_cpy = strdup(input);
	if (!input_cpy)
		return (NULL);
	return (_strtok(input_cpy, " \n"));
}
