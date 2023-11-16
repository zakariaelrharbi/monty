#include "monty.h"

/**
 * print_malloc_err - prints allocation error
 *
 */
void print_malloc_err(void)
{
	dprintf(2, "Error: malloc failed\n");
	code = -1;
}
/**
 * print_push_err - prints the push value err
 *@line_number: line number
 */
void print_push_err(unsigned int line_number)
{
	dprintf(2, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * print_opcode_err - print the opcode error
 * @line_number: line number
 * @tok1: the instruction string
 */
void print_opcode_err(unsigned int line_number, char *tok1)
{
	dprintf(2, "L%d: unknown instruction %s\n", line_number, tok1);
	code = -1;
}
/**
 * set_push_value - sets the value from str to char
 * @tok: pointer to token
 * @line_number: line number
 */
void set_push_value(char *tok, unsigned int line_number)
{
	if (isNumber(tok) == -1)
		print_push_err(line_number);
	n_data = atoi(tok);
}
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
	{"push", push}, {"pint", pint}, {"pall", pall},
	{"pop", pop}, {"add", add}, {"swap", swap},
	{"sub", sub}, {"nop", nop}, {"mul", mul},
{"div", _div}, {"mod", _mod}, {"pstr", pstr}, {"pchar", pchar}};
	if (token != NULL)
	{
		copy = malloc(sizeof(char) * (strlen(token) + 1));
		if (copy == NULL)
			print_malloc_err();
		else
		{
			strcpy(copy, token);
			tok1 = strtok(copy, " ");
			if (check_coms(tok1) == 0)
			{
				tok2 = strtok(NULL, " ");
				if (tok2)
					set_push_value(tok2, line_number);
				else
					print_push_err(line_number);
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
