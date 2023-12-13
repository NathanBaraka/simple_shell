#include "shell.h"

/**
 * client_information - Receive string input from the user
 * @rule: Buffer to store user input
 * @size: Size of the buffer
 *
 * This function receives string input from the user. If there is no input,
 * then just a new line is printed; otherwise, an error message is printed.
 */
void client_information(char *rule, size_t size)
{
	if (fgets(rule, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			nathan_myPrint("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error occurred while reading input");
			exit(EXIT_FAILURE);
		}
	}
	rule[strcspn(rule, "\n")] = '\0'; /* Removes a newline. */
}

