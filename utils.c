#include "monty.h"

/**
 * isNumber - checks if string contains a char or now
 * @number: pointer to string to check
 * Return: int
 */
int isNumber(char *number)
{
	int i = 0;

	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _strdup - copies and allocate a string
 * @src: pointer to source string
 * Return: char
 */
char *_strdup(const char *src)
{
	char *dst = NULL;

	if (src == NULL)
		return (NULL);
	dst = (char *)malloc(strlen(src) + 1);
	if (dst == NULL)
		return (NULL);
	strcpy(dst, src);
	return (dst);
}

/**
 * check_coms - checks if the line is a comment
 * @tok: pointer
 * Return: int
 */
int check_coms(char *tok)
{
	int i = 0;
	if (tok == NULL || tok[0] == '\0')
		return (-1);
	if (tok[i] == '#')
		return (-1);
	else
		return (0);
}
