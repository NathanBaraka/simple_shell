#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* enact_rule - Execute a shell command
* @rule: The command to be executed
*
* Description:
*     This function creates a child process to execute the specified command.
*     The parent process waits for the child to complete.
*/
void enact_rule(const char *rule)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
nathan_myPrint("Error forking process.\n");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{

char *args[147];
int arg_count = 0;

char *token = strtok((char *)rule, " ");
while (token != NULL)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;

execvp(args[0], args);

nathan_myPrint("Error executing command.\n");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

