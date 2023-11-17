#include "monty.h"
/**
* pstr - prints a string from ascci code in stack
* @stack: pointer to pointer to the head of the stack
* @line_number: the line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	int a;
	stack_t *temp = NULL;

	(void)line_number;
	if (*stack == NULL)
		printf("\n");
	else
	{
		temp = *stack;
		while (temp->a < 128 && temp && temp->a > 0)
		{
			printf("%c", a);
			temp = temp->next;
		}
		printf("\n");
	}

}
