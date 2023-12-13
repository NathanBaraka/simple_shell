 #include "shell.h"

 void enact_rule(const char *rule) {
     pid_t child_pid = fork(); 
/*
 * This function creates a child process
 * using folk
 */

   if (child_pid == -1) {
        perror("Part");
         exit(EXIT_FAILURE);

     } else if (child_pid == 0) {
/*This is the Child process that has been created
 */
        execlp(rule, rule, (char *)NULL);
        perror("execlp error");
        exit(EXIT_FAILURE);
     } else {
/*This is the Parent process that uses the wait function.
 * Until the child process is done.
 */
         wait(NULL);
    }
 }
