#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
/**
 *
 *
 *
 **/
int eval_fork(pid_t pid, char *cmd, char *cmd_cpy, char *argv[])
{
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Error");
	} else
		wait(NULL);
	free(cmd);
	free(cmd_cpy);
	free(argv);
	return (1);
}
/**
 *
 *
 *
 **/
int main(void)
{
	char *cmd, *cmd_cpy, *token;
	char *delim = " \n";
	size_t n;
	int argc, i;
	char **argv;
	
	while (1)
	{
		cmd = NULL;
		cmd_cpy = NULL;
		token = NULL;
		argv = NULL;
		i = 0;
		argc = 0;
		n = 0;

	printf("#code-here$ ");
	if (getline(&cmd, &n, stdin) == -1)
		return (-1);

	cmd_cpy = strdup(cmd);

	token = strtok(cmd, delim);

	while (token)
	{
		argc++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * argc);
	
	token = strtok(cmd_cpy, delim);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	eval_fork(fork(), cmd, cmd_cpy, argv);
	}
	return (0);
}
