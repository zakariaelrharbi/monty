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
* tok2_checker - checks tok2 value for further ops
* @line_number: the line number
* @tok1: the first token pointer
* @tok2: the seconde token pointer
*
*/
void tok2_checker(unsigned int line_number, char *tok2, char *tok1)
{
	if (tok2 && strcmp(tok1, "push") == 0)
		set_push_value(tok2, line_number);
	else if (tok2 == NULL && strcmp(tok1, "push") == 0)
		print_push_err(line_number);
}
