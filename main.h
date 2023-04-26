#ifndef ONE_H
#define ONE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
extern char **environ;
/**
 * struct built_in - struct for function pointers
 * @command: commands
 * @function: function
 **/
typedef struct built_in
{
	char *command;
	int (*function)();
} built_in;

/* In bulid.c */

int (*builtin_function(char *cmd))();
int exit_builtin(char **args, char *input_stdin, char *cpy_stdin);
int env_builtin(char **args, char *input_stdin, char *cpy_stdin);

/* In ... */
int only_spaces(char *cmd);
void sig_handler(int sig);
char **eval_token(char *tkn, char *argv[], char *cmd, char *cmd_cpy, char *dl);
char *get_location(char *command);
int eval_fork(pid_t pid, char *cmd, char *cmd_cpy, char *argv[], char *ex);
char *_getenv(const char *name);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
#endif
