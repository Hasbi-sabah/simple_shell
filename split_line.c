#include "head.h"

/**
 * replace_substring - check code
 * @str: input string
 * @old_substr: old substring
 * @new_substr: input substring
 * Return: command decomposition
 */
void replace_substring(char *str, char *old_substr, char *new_substr)
{
	char *ptr = _strstr(str, old_substr);
	size_t old_len = _strlen(old_substr);
	size_t new_len = _strlen(new_substr);
	int k = new_len, l = old_len;

	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l] != '\0');
	ptr[k] = '\0';
	_memcpy(ptr, new_substr, new_len);
	replace_substring(ptr + new_len, old_substr, new_substr);
}
/**
 * and_handling - check code
 * @line: input command line
 * @name: file name
 * Return: none
 */
void and_handling(char *line, char *name)
{
	char **arr, **line_split;

	line_split = _strtok(line, "&");
	while (*line_split)
	{
		arr = _strtok(*line_split, " \n");
		if (args_count(arr) > 0 && cmd_selector(arr[0], arr) == 0)
			_fork(name, arr);
		_free(arr);
		line_split++;
	}
	free(line);
}
/**
 * cmd_duplication - check code
 * @arr1: first args
 * @arr2: second args
 * Return: condition
 */
int cmd_duplication(char **arr1, char **arr2)
{
	int duplication, i;

	if (args_count(arr1) != args_count(arr2))
		return (0);
	for (i = 0; arr1[i] && arr2[i]; i++)
	{
		if (_strcmp(arr1[i], arr2[i]) != 0)
			return (0);
	}
	return (1);
}
/**
 * or_handling - check code
 * @line: input command line
 * @name: file name
 * Return: none
 */
void or_handling(char *line, char *name)
{
	char **arr1, **arr2, **line_split;
	int i = 0, j, duplication;

	line_split = _strtok(line, "|");
	while (line_split[i])
	{
		arr1 = _strtok(line_split[i], " \n");
		duplication = 0;
		for (j = 0; j < i; j++)
		{
			arr2 = _strtok(line_split[j], " \n");
			if (cmd_duplication(arr1, arr2))
			{
				duplication = 1;
				break;
			}			
		}
		if (duplication)
		{
			i++;
			continue;
		}
		if (args_count(arr1) > 0 && cmd_selector(arr1[0], arr1) == 0)
			_fork(name, arr1);
	        _free(arr1);
		i++;
	}
	free(line);
}
/**
 * split_line - read command line
 * @line: input command line
 * @name: file name
 * Return: none
 */
void split_line(char *line, char *name)
{
	size_t old_len = _strlen(line);
	char **arr, **line_split;

	replace_substring(line, "&&", "&");
	if (_strlen(line) < old_len)
	{
		and_handling(line, name);
		return;
	}
	replace_substring(line, "||", "|");
	if (_strlen(line) < old_len)
	{
		or_handling(line, name);
		return;
	}
	arr = _strtok(line, " \n");
	if (args_count(arr) > 0 && cmd_selector(arr[0], arr) == 0)
		_fork(name, arr);
	else
		_free(arr);
	free(line);
}
