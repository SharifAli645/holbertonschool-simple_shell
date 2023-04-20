#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
/**
 * eval_fork - function that receives the child and father
 * @pid: pid
 * @cmd: string
 * @cmd_cpy: string
 * @argv: argv
 *
 * Return: e
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
	return (0);
}
/**
 * eval_token - function that
 * @tkn: token
 * @argv: argv
 * @cmd: string
 * @cmd_cpy: string
 * @dl: delimitator
 *
 * Return: pointer to array
 **/
char **eval_token(char *tkn, char *argv[], char *cmd, char *cmd_cpy, char *dl)
{
	int i = 0;
	int argc = 0;

	tkn = strtok(cmd, dl);
	while (tkn)
	{
		argc++;
		tkn = strtok(NULL, dl);
	}
	argv = malloc(sizeof(char *) * argc);
	tkn = strtok(cmd_cpy, dl);
	while (tkn)
	{
		argv[i] = tkn;
		tkn = strtok(NULL, dl);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * main - main function
 * @arc: arc
 * @arv: arv
 *
 * Return: e
 **/
int main(int arc, char *arv[])
{
	char *cmd, *cmd_cpy, *token;
	char *delim = " \n";
	size_t n;
	char **argv;

	while (1)
	{
		cmd = NULL;
		cmd_cpy = NULL;
		token = NULL;
		argv = NULL;
		n = 0;

	printf("#code-here$ ");
	if (getline(&cmd, &n, stdin) == -1)
		return (-1);

	cmd_cpy = strdup(cmd);

	argv = eval_token(token, argv, cmd, cmd_cpy, delim);

	eval_fork(fork(), cmd, cmd_cpy, argv);

	}
	return (0);
}
