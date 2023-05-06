#include "head.h"

/**
 * execmd - execute
 * @arr: argument array
 */

void execmd(char **arr)
{
	char *comm = NULL;

	if (arr)
	{
		comm = arr[0];
		if (execve(comm, arr, NULL) == -1)
			perror("Error");
	}
}
