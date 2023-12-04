#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void show_prompt(void);
void nathan_myPrint(const char *myown_format);
void enact_rule(const char *rule);
void client_rule(char *rule, size_t size);


#endif 
