#include "shell.h"

/**
 * client_rule - Reads a rule from standard input
 * @rule: Buffer to store the rule
 * @size: Size of the buffer
 *
 * This function reads a rule from standard input using fgets.
 * If the end of file is reached, it prints a newline and exits successfully.
 * If an error occurs, it prints an error message and exits with failure.
 */
void client_rule(char *rule, size_t size)
{
if (fgets(rule, size, stdin) == NULL)
{
if (feof(stdin))
{
nathan_myPrint("\n");
exit(EXIT_SUCCESS);
}
else
{
nathan_myPrint("Error while reading input.\n");
exit(EXIT_FAILURE);
}
}
rule[strcspn(rule, "\n")] = '\0';
if (strcmp(rule, "exit") == 0)
{
handle_exit_command(rule);
}
}

/**
* handle_exit_command - Handles the "exit" command with an optional status
* @rule: The exit command with an optional status
*/
void handle_exit_command(const char *rule)
{
const char *exit_cmd = "exit";
int exit_status;

if (strncmp(rule, exit_cmd, strlen(exit_cmd)) == 0)
{
const char *status_str = rule + strlen(exit_cmd);
while (*status_str == ' ')
{
status_str++;
}

exit_status = atoi(status_str);
exit(exit_status);
}
}

