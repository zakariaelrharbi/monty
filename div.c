#include "monty.h"
/**
 * _div - perform div operation
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in the .m file
 *
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		code = -1;
	}
	else
	{

		temp = *stack;
		if (temp->n == 0)
		{
			dprintf(2, "L%d: division by zero\n", line_number);
			code = -1;
		}
		else
		{
			temp->next->n = temp->next->n / temp->n;
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(temp), temp = NULL;
		}
	}
}
