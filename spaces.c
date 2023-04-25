#include "main.h"
/**
 * only_spaces - function that evaluates blanks
 * @cmd: command
 *
 * Return: 1 if it's only blanks
 **/
int only_spaces(char *cmd)
{
	int j = 0, size = 0;

	size = strlen(cmd);
	while (cmd[j] == '\t' || cmd[j] == '\n' || cmd[j] == ' ')
		j++;
	if (size == j)
		return (1);
	return (0);
}
