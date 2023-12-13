#include "shell.h"

/**
 * custom_strtok - Custom string tokenizer
 * @str: String to tokenize
 * @delim: Delimiter character
 * @saveptr: Pointer to maintain state between calls
 *
 * This function tokenizes a string using the provided delimiter character.
 * It maintains the state between calls using a pointer.
 *
 * Return: On success, returns a pointer to the next token.
 * On failure, returns NULL.
 */
char *custom_strtok(char *str, const char *delim, char **saveptr)
{
	char *token;

	if (str == NULL)
		str = *saveptr;

	str += strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = str;
		return NULL;
	}

	token = str;
	str = strpbrk(token, delim);
	if (str == NULL)
	{
		*saveptr = token + strlen(token);
	}
	else
	{
		*str = '\0';
		*saveptr = str + 1;
	}

	return token;
}

