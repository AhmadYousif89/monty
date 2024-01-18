#include "monty.h"

/**
 * add - Sum the top two numbers on the stack or queue.
 * @head_ref: pointer to the head of the stack or queue.
 * @ln: the line number of of the opcode.
 */
void add(stack_t **head_ref, unsigned int ln)
{
	int res = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "add");

	(*head_ref) = (*head_ref)->next;
	res = (*head_ref)->n + (*head_ref)->prev->n;
	(*head_ref)->n = res;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}

/**
 * subtract - Subtract the top two numbers on the stack or queue.
 * @head_ref: pointer to the head of the stack or queue.
 * @ln: the line number of of the opcode.
 */
void subtract(stack_t **head_ref, unsigned int ln)
{
	int res = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "sub");

	(*head_ref) = (*head_ref)->next;
	res = (*head_ref)->n - (*head_ref)->prev->n;
	(*head_ref)->n = res;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}

/**
 * divid - Divid the top two numbers on the stack or queue.
 * @head_ref: pointer to the head of the stack or queue.
 * @ln: the line number of of the opcode.
 */
void divid(stack_t **head_ref, unsigned int ln)
{
	int res = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "div");

	if ((*head_ref)->n == 0)
		print_error(8, ln);

	(*head_ref) = (*head_ref)->next;
	res = (*head_ref)->n / (*head_ref)->prev->n;
	(*head_ref)->n = res;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}

/**
 * multiply - Multiply the top two numbers on the stack or queue.
 * @head_ref: pointer to the head of the stack or queue.
 * @ln: the line number of of the opcode.
 */
void multiply(stack_t **head_ref, unsigned int ln)
{
	int res = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "mul");

	(*head_ref) = (*head_ref)->next;
	res = (*head_ref)->n * (*head_ref)->prev->n;
	(*head_ref)->n = res;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}

/**
 * modules - Modules the top two numbers on the stack or queue.
 * @head_ref: pointer to the head of the stack or queue.
 * @ln: the line number of of the opcode.
 */
void modules(stack_t **head_ref, unsigned int ln)
{
	int res = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "mod");

	if ((*head_ref)->n == 0)
		print_error(8, ln);

	(*head_ref) = (*head_ref)->next;
	res = (*head_ref)->n % (*head_ref)->prev->n;
	(*head_ref)->n = res;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}
