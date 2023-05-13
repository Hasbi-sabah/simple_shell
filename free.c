#include "head.h"
/**
 * _free - frees
 * @arr: arr
 */
void _free(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
