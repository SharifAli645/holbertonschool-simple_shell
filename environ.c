#include "main.h"
/**
 * _getenv - function that gets the environment value from a env. variable
 * @name_env: environment variable name
 *
 * Return: value of the env. variable
 **/
char *_getenv(const char *name_env)
{
	char **env, *tmp;
	int i, j, len;

	if (name_env == NULL)
		return (NULL);
	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '='; len++)
			;
		len++;
		tmp = malloc(sizeof(char) * len);
		_memcpy(tmp, env[i], len - 1);
		tmp[len - 1] = '\0';

		if (strncmp((char *)name_env, tmp, _strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tmp = &env[i][j + 1];
					break;
				}
			}
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
/**
 * get_location - function that locates the command path
 * @command: command
 *
 * Return: a pointer to PATH, or NULL if it fail
 **/
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_size, drty_size;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_size = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token)
		{
			drty_size = _strlen(path_token);
			file_path = malloc(command_size + drty_size + 2);

			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			path_token = strtok(NULL, ":");

		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return(NULL);
	}
	return (NULL);
}
