#include "head.h"

/**
 * _getline - check code
 * @line: string to read
 * Return: string length
 */
int _getline(char **line)
{
	int i;

	*line = malloc(1024);
	i = read(STDIN_FILENO, *line, 1024);
	line[i] = '\0';
	return (i);
}
