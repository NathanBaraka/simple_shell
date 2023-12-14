#include "shell.h"

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
static char *line;
ssize_t chars_read;

if (line == NULL)
{
line = malloc(size);
if (line == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
}

nathan_myPrint(prompt);

chars_read = read(STDIN_FILENO, line, size);
if (chars_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}

if (chars_read == 0)
{
free(line);
return (-1);
}

line[chars_read - 1] = '\0';
strncpy(buffer, line, size);

return (chars_read);
}
