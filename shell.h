#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void nathan_myPrint(const char *myown_format);
void show_prompt(void);
void client_rule(char *rule, size_t size);
void enact_rule(const char *rule);
ssize_t custom_getline(char *buffer, size_t size, const char *prompt);
char *custom_strtok(char *str, const char *delim, char **saveptr);
void handle_exit_command(const char *rule);
char *construct_full_path(const char *command);

#endif /* SHELL_H */
