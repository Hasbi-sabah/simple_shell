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
	char *path = NULL, *comm = NULL, *error, *i_str;

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
	{
		i_str = malloc(20);
		i_str = int_to_str(i, i_str);
		error = malloc(strlen(i_str) + strlen(name)
				+ strlen(comm) + strlen(": : : not found\n") + 4);
		strcpy(error, name), strcat(error, ": ");
		strcat(error, i_str), strcat(error, ": ");
		strcat(error, comm), strcat(error, ": not found\n");
		write(2, error, strlen(error));
		free(error);
		free(i_str);
	}
}
