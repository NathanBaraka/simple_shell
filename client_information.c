#include "shell.h"
/*
*This function receives string input from the user
*If there is no input then just a new line is printed
* else print the error message.
*/
void client_rule(char *rule, size_t size) {
    if (fgets(rule, size, stdin) == NULL) {
        if (feof(stdin)) {
            nathan_myPrint("\n");
            exit(EXIT_SUCCESS);
        } else {
            nathan_myPrint("Error occured while reading input.\n");
            exit(EXIT_FAILURE);
        }
   
   } 
 /*
  *This removes the new line.
  */
    rule[strcspn(rule, "\n")] = '\0';

}
