#include "shell.h"
#include <unistd.h>

/**
 * nathan_my_print - Custom print function
 * @myown_format: String to be printed
 *
 * Description: This function prints a string to the standard output.
 */
void nathan_my_print(const char *myown_format)
{
    write(STDOUT_FILENO, myown_format, strlen(myown_format));
}
