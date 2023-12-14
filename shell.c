#include "shell.h"
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
if (custom_getline(rule, sizeof(rule), "Nathan_shell$$ ") == -1)
break;

enact_rule(rule);
}

return (0);
}
