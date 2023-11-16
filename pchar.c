#include "monty.h"
/**
* pchar - prints the top ascii value in stack as char
* @stack: pointer to pointer to the head of the stack
* @line_number: the line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int a;
	char c;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		code = -1;
	}
	else
	{
		a = (*stack)->n;
		if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		{
			c = (char)a;
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		else
		{
			dprintf(2, "L%d: can't pchar, value out of range", line_number);
			code = -1;
		}
	}
}
