#include "monty.h"
/**
 * pint - print the top element of the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in the .m file
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		code = -1;
	}
	else
		printf("%d\n", (*stack)->n);
}
