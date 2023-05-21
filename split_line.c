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
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "&\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " ");
		if (args_count(arr) == 0)
		{
	        	error(name, NULL, NULL, 9);
			_free(arr);
			_free(line_split);
			return;
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		break_condition = 0;
		arr = _strtok(line_split[i], " ");
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		_free(arr);
		if (break_condition)
			break;
		i++;
	}
	_free(line_split);
}
/**
 * or_handling - check code
 * @line: input command line
 * @name: file name
 * Return: none
 */
void or_handling(char *line, char *name)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "|\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " ");
		if (args_count(arr) == 0)
		{
	        	error(name, NULL, NULL, 9);
			_free(arr);
			_free(line_split);
			return;
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " ");
		break_condition = 0;
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name);
		if (argc > 0 && selector < 0)
			break_condition = _fork(name, arr);
		else if (argc > 0)
			break_condition = selector;
		_free(arr);
		if (break_condition)
			break;
		i++;
	}
	_free(line_split);
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
	int argc, i = 0;

	line_split = _strtok(line, ";\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " ");
		if (args_count(arr) == 0)
		{
	        	error(name, NULL, NULL, 9);
			_free(arr);
			_free(line_split);
			return;
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " ");
		argc = args_count(arr);
		if (argc > 0 && cmd_selector(arr[0], arr, name) < 0)
			_fork(name, arr);
		else if (argc == 0)
	        	error(name, NULL, NULL, 9);
		_free(arr);
		i++;
	}
	_free(line_split);
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
	size_t new_len;
	char *temp;


	temp = _strstr(line, "#");
	if (temp)
		*temp = '\0';
	replace_substring(line, "&&", "&");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "&&", "&");
		if (_strlen(line) < new_len)
			error(name, NULL, NULL, 7);
		else
			and_handling(line, name);
		return;
	}
	replace_substring(line, "||", "|");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "||", "|");
		if (_strlen(line) < new_len)
			error(name, NULL, NULL, 8);
		else
			or_handling(line, name);
		return;
	}
	if (_strstr(line, ";;"))
	        error(name, NULL, NULL, 9);
	else
		semi_column_handling(line, name);
}
