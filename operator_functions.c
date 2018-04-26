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

	adding = variables.holder;
	pop(stk, linenum);
	adding += variables.holder;
	pop(stk, linenum);
	variables.holder = adding;
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

	subtract = variables.holder;
	pop(stk, linenum);
	subtract = variables.holder - subtract;
	pop(stk, linenum);
	variables.holder = subtract;
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

	if (variables.holder == 0)
	{
		printf("L%d: division by zero\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	divide = variables.holder;
	pop(stk, linenum);
	divide = variables.holder / divide;
	pop(stk, linenum);
	variables.holder = divide;
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

	multiply = variables.holder;
	pop(stk, linenum);
	multiply = variables.holder * multiply;
	pop(stk, linenum);
	variables.holder = multiply;
	push(stk, linenum);
}



/**
 * mod - function to find rem top two elements on stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void mod(stack_t **stk, unsigned int linenum)
{
	int rem;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	if (variables.holder == 0)
	{
		printf("L%d: division by zero\n", linenum);
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	rem = variables.holder;
	pop(stk, linenum);
	rem = variables.holder % rem;
	pop(stk, linenum);
	variables.holder = rem;
	push(stk, linenum);
}
