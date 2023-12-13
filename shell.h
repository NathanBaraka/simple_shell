#ifndef SHELL_H
#define SHELL_H
/* 
 * These are the the libraries to be used.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 * these are the prototypes on each program.
 */
void show_prompt(void);
void nathan_myPrint(const char *myown_format);
void enact_rule(const char *rule);
void client_rule(char *rule, size_t size);


#endif 
