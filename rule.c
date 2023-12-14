#include "shell.h"

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
perror("Fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execlp("/bin/sh", "/bin/sh", "-c", rule, (char *)NULL);
perror("execlp error");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
