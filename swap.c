#include "monty.h"
/**
 * swap - perform swap operation on stack
 * @stack: pointer to pointer to the stack  head
 * @line_number: the line number
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int t;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		code = -1;
	}
	else
	{
		temp = *stack;
		t = temp->n;
		temp->n = temp->next->n;
		temp->next->n = t;
	}
}
