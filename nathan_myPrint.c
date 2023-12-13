#include "shell.h"
/*
 * This is my own printf function
 */

void nathan_myPrint(const char *myown_format) 
{
   write(STDOUT_FILENO, myown_format, strlen(myown_format));
}

