#include "monty.h"

int holder;

/**
 *
 *
 *
 *
 */
void _tokenizer(char *string, stack_t **stk, unsigned int linenum)
{
	char *token;
	char *tokens;

	token = strtok(string, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!check_digit(token))
		{
			printf("L%d: usage: push integer\n", linenum);
			free_stk(stk, linenum);
			exit(EXIT_FAILURE);
		}
		holder = atoi(token);
		_ops(tokens, stk, linenum);
	}
	else
		_ops(token, stk, linenum);
}
