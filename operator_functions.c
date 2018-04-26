#include "monty.h"

/**
 * add - function to add top two elements on stack
 * @stk: stack
 * @linenum: line number
 * Return: void
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

/**
 * add - function to add top two elements on stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void sub(stack_t **stk, unsigned int linenum)
{
	int subtract;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	subtract = holder;
	pop(stk, linenum);
	subtract = holder - subtract;
	pop(stk, linenum);
	holder = subtract;
	push(stk, linenum);
}
