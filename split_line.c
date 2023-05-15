#include "head.h"

/**
 * replace_substring - check code
 * @str: input string
 * Return: command decomposition
 */
void replace_substring(char* str, const char* old_substring, const char* new_substring)
{
	char* substring_ptr = strstr(str, old_substring);
	size_t old_len = strlen(old_substring);
	size_t new_len = strlen(new_substring);

	if (substring_ptr != NULL)
		memmove(substring_ptr + new_len, substring_ptr + old_len, strlen(substring_ptr + old_len) + 1);
	memcpy(substring_ptr, new_substring, new_len);
	replace_substring(substring_ptr + new_len, old_substring, new_substring);
}
/**
 * split_line - read command line
 * @input: input command line
 * Return: command decomposition
 */
char **split_line(char *input)
{
}
