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
info_t info[] = { INFO_INIT };
char rule[147];

int fd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));

if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fd;
}
while (1)
{
show_prompt();
if (custom_getline(rule, sizeof(rule), "Nathan_shell$$ ") == -1)
break;
enact_rule(rule);
}
return (EXIT_SUCCESS);
}
