#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - Entry point for the shell program
 *
 * Description:
 *     This function invokes the shell in an infinite loop.
 *     It shows the prompt, reads a rule, and executes it.
 *
 * Return: Always 0 (indicating successful execution)
 */

int main(void)
{
char rule[147];

while (1)
{
show_prompt();
client_rule(rule, sizeof(rule));
enact_rule(rule);
}

return (0);
}

/**
 * nathan_myPrint - Custom print function
 * @myown_format: String to be printed
 *
 * Description: This function prints a string to the standard output.
 */
void nathan_myPrint(const char *myown_format)
{
write(STDOUT_FILENO, myown_format, strlen(myown_format));
}

