#include "monty.h"

/**
* tokenizer - tokenize the line even more
* @token: the tokenized line passed from main
* @line_number: the line number
* @head: pointer to pointer to the head of the stack
*
*/
void tokenizer(char *token, unsigned int line_number, stack_t **head)
{
	char *tok1 = NULL, *tok2 = NULL, *copy = NULL;
	int i, flag = 0;

	instruction_t op[OPCODE_LEN] = {
	{"push", push},
{"pint", pint}, {"pall", pall}, {"pop", pop}, {"add", add},
{"swap", swap}, {"sub", sub}, {"nop", nop}, {"mul", mul},
{"div", _div}, {"mod", _mod}, {"pstr", pstr}, {"pchar", pchar}};
	if (token != NULL)
	{
	/*	printf("token = %s\n", token);*/
		copy = malloc(sizeof(char) * (strlen(token) + 1));
		if (copy == NULL)
			print_malloc_err();
		else
		{
			strcpy(copy, token);
			tok1 = strtok(copy, " ");
                        /*printf("tok1 = %s\n", tok1);*/
			if (check_coms(tok1) == 0)
			{
				tok2 = strtok(NULL, " ");
				/*printf("tok2 = %s\n", tok2);*/
				tok2_checker(line_number, tok2, tok1);
				for (i = 0; i < OPCODE_LEN; i++)
				{
					if (strcmp(tok1, (op[i]).opcode) == 0)
					{
						((op[i]).f)(head, line_number);
						flag = 1;
						break;
					}
				}
					if (flag == 0 && tok1 != NULL)
						print_opcode_err(line_number, tok1);
			}
			free(copy);
		}
	}
}
