#include "monty.h"

/**
 * push - push the element onto the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in the .m file
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	(void)line_number;
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		code = -1;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->n = n_data;
		if (*stack == NULL)
			*stack = new_node;
		else
		{
			new_node->next = *stack;
			if ((*stack)->next != NULL)
				(*stack)->next->prev = new_node;
			*stack = new_node;
		}
	}
}
