#include "head.h"

void check_fork_error(char *comm, char **args, char *name)
{
	pid_t pid;
	int status;
	static int i = 0;
	int j, k;
	char *error_msg = NULL, temp[20], *p = NULL;

	i++;
	printf("-%s\n", comm);
	if (is_path(comm) || (p = is_command(comm)))
	{
		pid = fork();
		if (pid == 0)
		{
			execmd(args, p);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		free(comm);
	}
	else
	{
		printf("here??\n");
		strcpy(error_msg, name);
		strcat(error_msg, ": ");
		for (j = 0, k = i; k > 0; j++)
			k /= 10;
		for (k = i; k > 0; j--)
		{
			temp[j] = k % 10 + '0';
			k /= 10;
		}
		strcat(error_msg, temp);
		strcat(error_msg, ": ");
		strcat(error_msg, comm);
		strcat(error_msg, ": not found\n");
		write(2, error_msg, strlen(error_msg));
	}
}
/**
 * execmd - execute
 * @arr: argument array
 * @name: name
 * Return: none
 */
void execmd(char **arr, char *path)
{
	char *comm = NULL, *env;

	comm = arr[0];
	if (path)
	{
		strcat(path, "/");
		strcat(path, comm);
		strcpy(comm, path);
		strcpy(arr[0], path);
		if (strstr(comm, "echo"))
		{
			env = getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				strcpy(arr[1], env);
			}
		}
	}
	execve(comm, arr, environ);
}
