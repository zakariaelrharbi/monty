#include "monty.h"
/**
 * pall - print all the elements of the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in the .m file
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
