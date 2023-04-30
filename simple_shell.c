#include "main.h"
/**
 * eval_fork - function that receives the child and father
 * @cmd: string
 * @cmd_cpy: string
 * @argv: argv
 * @ex: binary
 *
 * Return: e
 **/
int eval_fork(char *cmd, char *cmd_cpy, char *argv[], char *ex)
{
	char *actual_command = NULL;
	pid_t pid;
	int exit_status = 0;

	actual_command = get_location(argv[0]);
	if (access(actual_command, F_OK) == -1)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", ex, argv[0]);
		exit_status = 127;

	} else
	{
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (execve(actual_command, argv, environ) == -1)
			perror(ex);
	} else
		wait(NULL);
	}
	free(cmd);
	free(cmd_cpy);
	free(argv);

	return (exit_status);
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
	argv = malloc(sizeof(char *) * (argc + 1));
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
 * sig_handler - function that print prompt
 * @sig: sign
 *
 * Return: Always void
 **/
void sig_handler(int sig)
{
	if (sig == SIGINT)
		write(2, "\n#code: ", 7);
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
	char *cmd = NULL, *cmd_cpy, *token;
	char *delim = " \n";
	char **argv;
	int ex_st = 0;
	size_t n = 0;

	(void)arc;
	while (1)
	{
		cmd = NULL;
		cmd_cpy = NULL;
		token = NULL;
		argv = NULL;
		ex_st = 0;
		n = 0;

		if (isatty(STDIN_FILENO))
			write(2, "#code: ", 7);
		signal(SIGINT, sig_handler);
		if (getline(&cmd, &n, stdin) == -1)
		{
			free(cmd);
			break;
		}
		if (only_spaces(cmd))
		{
			free(cmd);
			continue;
		}
		cmd_cpy = _strdup(cmd);
		argv = eval_token(token, argv, cmd, cmd_cpy, delim);
		if (builtin_function(argv[0]))
			ex_st = builtin_function(argv[0])(argv, cmd, cmd_cpy);
		else
			ex_st = eval_fork(cmd, cmd_cpy, argv, arv[0]);
	}
	return (ex_st);
}
