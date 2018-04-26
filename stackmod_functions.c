#include "monty.h"

/**
 * pchar - function to print first char in the top of stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void pchar(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	if (isascii(variables.holder))
		printf("%c\n", variables.holder);
	else
	{
		printf("L%d: can't pchar, value out of range\n", linenum);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints string
 * @stk: stack
 * @linenum: unused
 * Return: void
 */
void pstr(stack_t **stk, __attribute__((unused)) unsigned int linenum)
{
	stack_t *str;

	if (stk == NULL || *stk == NULL || variables.holder == 0)
	{
		printf("\n");
		return;
	}

	str = *stk;

	while (str != NULL && str->n != 0 && isascii(str->n))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");

}

/**
 * rotl - rotates stack from top to bottom once
 * @stk: stack
 * @linenum: unused
 * Return: void
 */
void rotl(stack_t **stk, __attribute__((unused))unsigned int linenum)
{
	stack_t *new;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;
	new = *stk;

	while (new->next != NULL)
		new = new->next;

	new->next = *stk;
	(*stk)->prev = new;
	*stk = (*stk)->next;
	(*stk)->prev = NULL;
	new->next->next = NULL;
}

/**
 * rotr - function to rotate bottom to the top once
 * @stk: stack
 * @linenum: unused
 * Return: void
 */
void rotr(stack_t **stk, __attribute__((unused))unsigned int linenum)
{
	stack_t *rev;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	rev = *stk;

	while (rev->next != NULL)
		rev = rev->next;
	rev->next = *stk;
	rev->prev->next = NULL;
	rev->prev = NULL;
	(*stk)->prev = rev;
	*stk = rev;
}
