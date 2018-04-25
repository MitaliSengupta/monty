#include "monty.h"

/**
 *
 *
 *
 *
 *
 */
void push(stack_t **stk, unsigned int linenum)
{
	stack_t *new;

	if (stk == NULL)
	{
		printf("L%d: unknown stack\n", linenum);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}
	new->n = holder;
	new->prev = NULL;
	new->next = *stk;

	if (*stk != NULL)
		(*stk)->prev = new;
	*stk = new;
}

/**
 *
 *
 *
 *
 *
 *
 */
void pall(stack_t **stk, unsigned int linenum)
{
	stack_t *print;

	if (stk == NULL)
	{
		printf("L%d: invalid stack\n", linenum);
		exit(EXIT_FAILURE);
	}

	print = *stk;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 *
 *
 *
 *
 *
 *
 */
void pop(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pop an empty stack\n", linenum);
		exit(EXIT_FAILURE);
	}
	if ((*stk)->next != NULL)
	{
		*stk = (*stk)->next;
		holder = (*stk)->n;
		free((*stk)->prev);
		(*stk)->prev = NULL;
	}
	else
	{
		free(*stk);
		*stk = NULL;
	}
}

/**
 *
 *
 *
 *
 *
 */
void pint(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stk)->n);
}

/**
 *
 *
 *
 *
 *
 */
void swap(stack_t **stk, unsigned int linenum)
{
	int temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}
	temp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = temp;
}
