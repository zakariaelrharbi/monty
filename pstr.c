#include "monty.h"
/**
* pstr - prints a string from ascci code in stack
* @stack: pointer to pointer to the head of the stack
* @line_number: the line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	int a;
	char c;
	stack_t *temp = NULL;

	(void)line_number;
	if (*stack == NULL)
		printf("\n");
	else
	{
		temp = *stack;
		a = temp->n;
		while (((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) && temp && a > 0)
		{
			c = (char)a;
			write(1, &c, 1);
			temp = temp->next;
			if (temp)
			a = temp->n;
		}
		write(1, "\n", 1);
	}

}
