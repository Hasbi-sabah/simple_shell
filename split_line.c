#include "head.h"

/**
 * and_handling - check code
 * @line: input command line
 * @name: file name
 * Return: none
 */
void and_handling(char *line, char *name)
{
	char **arr, **line_split;
	int break_condition, argc, selector;

	line_split = _strtok(line, "&");
	while (*line_split)
	{
		break_condition = 0;
		arr = _strtok(*line_split, " \n");
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		_free(arr);
		if (break_condition)
			break;
		line_split++;
	}
}
/**
 * cmd_duplication - check code
 * @arr1: first args
 * @arr2: second args
 * Return: condition
 */
int cmd_duplication(char **arr1, char **arr2)
{
	int i;

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
	int break_condition, argc, selector;

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
				_free(arr2);
				break;
			}
			_free(arr2);
		}
		if (duplication)
		{
			i++;
			continue;
		}
		break_condition = 0;
		argc = args_count(arr1);
		selector = cmd_selector(arr1[0], arr1, name);
		if (argc > 0 && selector < 0)
			break_condition = _fork(name, arr1);
		else if (argc > 0)
			break_condition = selector;
		_free(arr1);
		if (break_condition)
			break;
		i++;
	}
}
/**
 * semi_column_handling - check code
 * @line: input command line
 * @name: file name
 * Return: none
 */
void semi_column_handling(char *line, char *name)
{
	char **arr, **line_split;

	line_split = _strtok(line, ";");
	while (*line_split)
	{
		arr = _strtok(*line_split, " \n");
		if (args_count(arr) > 0 && cmd_selector(arr[0], arr, name) < 0)
			_fork(name, arr);
		_free(arr);
		line_split++;
	}
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
	char *temp;


	temp = _strstr(line, "#");
	if (temp)
		*temp = '\0';
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
	semi_column_handling(line, name);
}
