#include "monty.h"

/**
 * free_stk - function to free stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void free_stk(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL)
		return;
	while (*stk != NULL)
		pop(stk, linenum);
}
