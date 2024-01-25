#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln, char *op);
} instruction_t;

typedef void (*op_func)(stack_t **, unsigned int, char *);

/* PROTOTYPES */

void validate_args(int);
void open_monty(char *);
void read_monty(FILE *);
int parse_line(char *, int, int, FILE *);

void get_op(char *, char *, int, int, FILE *);
void run_monty_op(op_func, char *, char *, int, int);

stack_t *create_node(int);
void add_to_stack(stack_t **, unsigned int, char *);
void add_to_queue(stack_t **, unsigned int, char *);
void free_stack(void);

void pop(stack_t **, unsigned int, char *);
void nop(stack_t **, unsigned int, char *);
void swap(stack_t **, unsigned int, char *);
void rotl(stack_t **, unsigned int, char *);
void rotr(stack_t **, unsigned int, char *);
void calc(stack_t **, unsigned int, char *);
void print_all(stack_t **, unsigned int, char *);
void print_top(stack_t **, unsigned int, char *);
void print_char(stack_t **, unsigned int, char *);
void print_str(stack_t **, unsigned int, char *);
void print_str_reverse(stack_t **, unsigned int, char *);

void print_error(int, ...);

#endif
