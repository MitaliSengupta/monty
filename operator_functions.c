#include "monty.h"

/**
 *
 *
 *
 *
 *
 */
void add(stack_t **stk, unsigned int linenum)
{
	int adding;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	adding = holder;
	pop(stk, linenum);
	adding += holder;
	pop(stk, linenum);
	holder = adding;
	push(stk, linenum);
}
