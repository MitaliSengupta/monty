#include "monty.h"

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
	for (; *token != '\0'; token++)
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	return (1);
}
