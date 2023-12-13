#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * enact_rule - Execute a rule using fork and execlp
 * @rule: The rule to be executed
 *
 * Description:
 *     This function creates a child process to execute the specified rule.
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
        execlp(rule, rule, (char *)NULL);
        perror("execlp error");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}

