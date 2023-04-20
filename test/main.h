#ifndef ONE_H
#define ONE_H
#include <unistd.h>
extern char **environ;
char **eval_token(char *tkn, char *argv[], char *cmd, char *cmd_cpy, char *delim);
int eval_fork(pid_t pid, char *cmd, char *cmd_cpy, char *argv[]);
#endif
