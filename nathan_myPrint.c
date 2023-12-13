#include "shell.h"
#include <unistd.h>
/**
 * nathan_myPrint - Custom print function
 * @myown_format: String to be printed
 *
 * This function prints a string to the standard output.
 */
void nathan_myPrint(const char *myown_format)
{
write(STDOUT_FILENO, myown_format, strlen(myown_format));
}
