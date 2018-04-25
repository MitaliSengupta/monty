#include "monty.h"


int holder;


/**
 *
 *
 *
 *
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *buff = NULL, *string;
	size_t s = 0;
	unsigned int linenum = 1;
	stack_t *stk = NULL;

	if (argc != 2)
    {
	    printf("USAGE: monty file");
	    exit(EXIT_FAILURE);
    }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &s, file) != -1)
	{
		if (*buff != '\n')
		{
			string = strtok(buff, "\n");
			_tokenizer(string, &stk, linenum);
		}
		linenum++;
	}
	fclose(file);
	free(buff);
	free(string);
	if (stk != NULL)
		free_stk(&stk, linenum);
	return (0);
}

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

/**
 *
 *
 *
 *
 *
 */
int check_digit(char *token)
{
	if (token == NULL)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
