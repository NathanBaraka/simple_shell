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
}
