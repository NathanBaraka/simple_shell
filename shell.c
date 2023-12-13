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
void show_prompt(void);
void client_rule(char *rule, size_t size);
enact_rule(rule);
}

return (0);
}
