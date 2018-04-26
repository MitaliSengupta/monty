#include "monty.h"

/**
 * _ops - compare functions to tokens and executes them
 * @token: command recieved
 * @stk: stack
 * @linenum: number of line
 * Return: void
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
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (strcmp(token, "stack") == 0)
	{
		variables.check = 0;
		return;
	}

	if (strcmp(token, "queue") == 0)
	{
		variables.check = 1;
		return;
	}

	if (variables.check == 1 && strcmp(token, "push") == 0)
	{
		_queue(stk, linenum);
		return;
	}

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
 * nop - function does nothing
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void nop(stack_t **stk, unsigned int linenum)
{
	(void)stk;
	(void)linenum;
}
