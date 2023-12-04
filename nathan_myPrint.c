#include "shell.h"


void nathan_myPrint(const char *myown_format) {
//my unique message
   write(STDOUT_FILENO, myown_format, strlen(myown_format));
}

