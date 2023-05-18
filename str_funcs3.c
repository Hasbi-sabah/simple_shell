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
	memcpy(ptr, new_substr, new_len);
	replace_substring(ptr + new_len, old_substr, new_substr);
}
