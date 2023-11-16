#include "monty.h"

int code, n_data;

/**
 * handle_code - handles freeing copy and stack
 * @head: pointer to pointer to the head of stack
 * @cp: pointer to a string
 * @file: pointer to file
 */
void handle_code(stack_t **head, char *cp, FILE *file)
{
	free(cp), cp = NULL;
	if (*head)
		free_stack(head);
	if (file)
		fclose(file);
	exit(EXIT_FAILURE);
}

/**
* main - the main function
* @argc: counter of arguments
* @argv: array of args
* Return: int
*/
int main(int argc, const char **argv)
{
	FILE *file;
	unsigned int line = 1;
	char buff[1024], *token = NULL, *saveptr = NULL, *copy = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, 1024, file) != NULL)
	{
		copy = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
		if (!copy)
		{
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(copy, buff);
		token = strtok_r(copy, "\n", &saveptr);
		tokenizer(token, line, &head);
		if (code == -1)
			handle_code(&head, copy, file);
		free(copy), copy = NULL;
		line++;
	}
	fclose(file);
	free_stack(&head);
	return (0);
}
