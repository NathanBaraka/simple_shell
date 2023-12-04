#include "shell.h"
/* It evokes the shell
 * Takes the show_prompt and gives the required output
 */

int main(void) {
    char rule[147];

    while (true) {
       show_prompt();
        read_rule(rule, sizeof(rule)); 
 	execute_rule(rule);
 
    }

     return 0;
 }

