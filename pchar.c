#include "monty.h"
/**
* pchar - prints the top ascii value in stack as char
* @stack: pointer to pointer to the head of the stack
* @line_number: the line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		code = -1;
	}
	else
	{
		if ((*stack)->n >= 0 && (*stack)->n < 128)
			printf("%c\n", (*stack)->n);
		else
		{
			dprintf(2, "L%d: can't pchar, value out of range", line_number);
			code = -1;
		}
	}
}
