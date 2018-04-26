#include "monty.h"

/**
 * push - adds to the beginning of the stack
 * @stk: top of stack
 * @linenum: line number for the passed token
 * Return: void
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
	new->n = variables.holder;
	new->prev = NULL;
	new->next = *stk;

	if (*stk != NULL)
		(*stk)->prev = new;
	*stk = new;
}

/**
 * pall - function prints all of stack
 * @stk: top of stack
 * @linenum: line number
 * Return: void
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
 * pop - function to pop the top of stack
 * @stk: top of stack
 * @linenum: line number
 * Return: void
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
		variables.holder = (*stk)->n;
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
 * pint - function prints the value at the top of the stack
 * @stk: stack
 * @linenum: line number
 * Return: void
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
 * swap - swapping first two elements on top of stack
 * @stk: stack
 * @linenum: line number
 * Return: void
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
