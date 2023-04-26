#include "main.h"
/**
 * builtin_function - function that checks if the command is a built-in
 * @command: command
 * Return: Pointer to function
 **/
int (*builtin_function(char *command))()
{
	int i = 0;

	built_in array[] = {
		{"exit", exit_builtin},
		{NULL, NULL}
	};
	while (*array[i].function != NULL)
	{
		if (_strcmp(array[i].command, command) == 0)
			return (array[i].function);
		i++;
	}
	return (NULL);

}
/**
 * exit_builtin - function that execute 'exit' built-in
 * @args: arguments
 * @input_stdin: input of stdin
 * @cpy_stdin: copy from stdin
 *
 * Return: exit success
 **/
int exit_builtin(char **args, char *input_stdin, char *cpy_stdin)
{
	int exit_status = 0;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		free(cpy_stdin);
		exit(exit_status);
	}
	return (0);
}
