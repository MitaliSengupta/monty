#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef struct var
{
	int holder;
	char check;
}var_t;

extern var_t variables;
var_t variables;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _tokenizer(char *string, stack_t **stk, unsigned int linenum);
void free_stk(stack_t **stk, unsigned int linenum);
int check_digit(char *token);
void _ops(char *token, stack_t **stk, unsigned int linenum);
void push(stack_t **stk, unsigned int linenum);
void pall(stack_t **stk, unsigned int linenum);
void pint(stack_t **stk, unsigned int linenum);
void pop(stack_t **stk, unsigned int linenum);
void swap(stack_t **stk, unsigned int linenum);
void add(stack_t **stk, unsigned int linenum);
void nop(stack_t **stk, unsigned int linenum);
void sub(stack_t **stk, unsigned int linenum);
void _div(stack_t **stk, unsigned int linenum);
void mul(stack_t **stk, unsigned int linenum);
void mod(stack_t **stk, unsigned int linenum);
void pchar(stack_t **stk, unsigned int linenum);
void pstr(stack_t **stk, unsigned int linenum);
void rotl(stack_t **stk, unsigned int linenum);
void rotr(stack_t **stk, unsigned int linenum);
void _queue(stack_t **stk, unsigned int linenum);

#endif
