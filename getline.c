#include "head.h"

/**
 * _getline - check code
 * @line: string to read
 * Return: string length
 */
int _getline(char **line)
{
	int i;

	*line = malloc(10240);
	i = read(STDIN_FILENO, *line, 10240);
	while (**line == ' ')
		(*line)++, i--;
	(*line)[i] = '\0';
	return (i);
}
