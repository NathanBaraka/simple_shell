#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * This function evokes the shell in an infinite loop.
 * It shows the prompt, reads a rule, and executes it.
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

    return 0;
}
