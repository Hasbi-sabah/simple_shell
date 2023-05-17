#include "head.h"

/**
 * int_to_str - check code
 * @n: command name
 * @s: string
 * Return: string
 */
char *int_to_str(int n, char *s)
{
	int i, j;
	char temp;

	for (i = 0; n > 0; i++, n /= 10)
		s[i] = n % 10 + '0';
	for (j = 0; j < i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = temp;
	}
	return (s);
}
/**
 * _fork - check code
 * @name: command name
 * @arr: arguments
 * Return: none
 */
void _fork(char *name, char **arr)
{
	pid_t pid;
	static int i;
	int status;
	char *path = NULL, *comm = NULL;

	i++;
	comm = arr[0];
	path = is_valid(comm);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			execmd(arr, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
	}
	else
		_printf("%s: %i: %s: not found\n", name, i, comm);
}
