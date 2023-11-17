#include "monty.h"

/**
 * pop - pops the top of stack
 * @stack : pointer to pointer to the stack:x
 * @line_number: the line number
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
		stack_t *temp = NULL;

		(void)line_number;
		if (*stack == NULL)
		{
			dprintf(2, "L%d: can't pop an empty stack\n", line_number);
			code = -1;
		}
		else
		{
			temp = *stack;
			*stack = (*stack)->next;
			if (*stack != NULL)
				(*stack)->prev = NULL;
			free(temp), temp = NULL;
		}
}
