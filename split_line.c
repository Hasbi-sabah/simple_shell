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
	size_t old_len = strlen(old_substr);
	size_t new_len = strlen(new_substr);

	if (!ptr)
		return;
	memmove(ptr + new_len, ptr + old_len, strlen(ptr + old_len) + 1);
	memcpy(ptr, new_substr, new_len);
	replace_substring(ptr + new_len, old_substr, new_substr);
}
/**
 * split_line - read command line
 * @line: input command line
 * Return: none
 */
void split_line(char *line, char *name)
{
	size_t old_len = _strlen(line);
	char **arr, **line_split;

	replace_substring(line, "&&", "&");
	if (_strlen(line) < old_len)
	{
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
		return;
	}
	//replace_substring(line, "||", "|");
	arr = _strtok(line, " \n");
	if (args_count(arr) > 0 && cmd_selector(arr[0], arr) == 0)
		_fork(name, arr);
	else
		_free(arr);
	free(line);
}
