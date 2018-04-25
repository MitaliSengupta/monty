#include "monty.h"

/**
 *
 *
 *
 *
 *
 *
 */
void _ops(char *token, stack_t **stk, unsigned int linenum)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (op[a].opcode != NULL)
	{
		if (strcmp(token, op[a].opcode) == 0)
		{
			op[a].f(stk, linenum);
			return;
		}
		a++;
	}
	printf("L%d: unknown instruction %s\n", linenum, token);
	free_stk(stk, linenum);
	exit(EXIT_FAILURE);
}

/**
 *
 *
 *
 *
 */
void nop(stack_t **stk, unsigned int linenum)
{
        (void) stk;
	(void) linenum;
	return;
}
