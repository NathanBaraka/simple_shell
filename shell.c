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
/**
 * show_prompt - Display the shell prompt
 *
 * This function prints the shell prompt to the standard output.
 */
void show_prompt(void)
{
nathan_myPrint("Nathan_shell$$ ");
}
/**
 * custom_getline - Read an entire line from input
 * @buffer: Buffer to store the line
 * @size: Size of the buffer
 * @prompt: Prompt to display
 *
 * This function reads an entire line from the input using a buffer.
 * It calls the least possible read system calls by reusing static variables.
 * It does not provide cursor movement.
 *
 * Return: On success, returns the number of characters read
 * On failure, returns -1.
 */
ssize_t custom_getline(char *buffer, size_t size, const char *prompt)
{
ssize_t chars_read;

if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
{
perror("write");
exit(EXIT_FAILURE);
}

chars_read = read(STDIN_FILENO, buffer, size);
if (chars_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}

buffer[chars_read - 1] = '\0';
return chars_read;
}
/**
 * custom_strtok - Custom string tokenizer
 * @str: String to tokenize
 * @delim: Delimiter character
 * @saveptr: Pointer to maintain state between calls
 *
 * This function tokenizes a string using the provided delimiter character.
 * It maintains the state between calls using a pointer.
 *
 * Return: On success, returns a pointer to the next token.
 * On failure, returns NULL.
 */
char *custom_strtok(char *str, const char *delim, char **saveptr)
{
char *token;

if (str == NULL)
str = (*saveptr);

str += strspn(str, delim);
if (*str == '\0')
{
*saveptr = str;
return (NULL);
}

token = str;
str = strpbrk(token, delim);
if (str == NULL)
{
*saveptr = token + strlen(token);
}
else
{
*str = '\0';
*saveptr = str + 1;
}

return (token);
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
