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
void read_rule(char *rule, size_t size);
void enact_rule(const char *rule);

#endif /* SHELL_H */

