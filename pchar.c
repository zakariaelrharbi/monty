#include "monty.h"
/**
* pchar - prints the top ascii value in stack as char
* @stack: pointer to pointer to the head of the stack
* @line_number: the line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int a;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		code = -1;
	}
	else
	{
		a = (*stack)->n;
		if (a >= 0 && a < 128)
			printf("%c\n", a);
		else
		{
			dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
			code = -1;
		}
	}
}
