#include "monty.h"
/**
 * free_stack - frees the stack
 * @h: pointer to pointer to the ehad of stack
 *
 */
void free_stack(stack_t **h)
{
	stack_t *temp = NULL;

	while (*h)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp), temp = NULL;
	}
}
