#include "head.h"

/**
 * _getline - check code
 * @line: string to read
 * Return: string length
 */
int _getline(char **line)
{
	*line = malloc(1024);
	return (scanf("%s", *line));
}