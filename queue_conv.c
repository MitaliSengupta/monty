#include "monty.h"

/**
 * _queue - FIFO
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void _queue(stack_t **stk, unsigned int linenum)
{
	stack_t *new = NULL;
	stack_t *old = NULL;

	if (stk == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	new->n = variables.holder;
	new->next = NULL;

	if (*stk == NULL)
	{
		new->prev = NULL;
		*stk = new;
		return;
	}

	old = *stk;

	while (old->next != NULL)
		old = old->next;

	old->next = new;
	new->prev = old;
	variables.holder = (*stk)->n;
}
