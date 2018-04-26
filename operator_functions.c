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
 * sub - function to subtract top two elements on stack
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

/**
 * _div - function to divide top two elements on stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void _div(stack_t **stk, unsigned int linenum)
{
	int divide;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	if (holder == 0)
	{
		printf("L%d: division by zero\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	divide = holder;
	pop(stk, linenum);
	divide = holder / divide;
	pop(stk, linenum);
	holder = divide;
	push(stk, linenum);
}


/**
 * mul - function to multiply top two elements on stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void mul(stack_t **stk, unsigned int linenum)
{
	int multiply;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	multiply = holder;
	pop(stk, linenum);
	multiply = holder * multiply;
	pop(stk, linenum);
	holder = multiply;
	push(stk, linenum);
}
