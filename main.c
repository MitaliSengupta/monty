#include "monty.h"

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
	if (stk != NULL)
		free_stk(&stk, linenum);
}
