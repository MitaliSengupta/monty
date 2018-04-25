#include "monty.h"

void free_stk(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL)
		return;
	while (*stk != NULL)
		pop(stk, linenum);
}
