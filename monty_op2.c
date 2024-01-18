#include "monty.h"

/**
 * pop - Remove a the top node from the stack.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of of the opcode.
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void pop(stack_t **head_ref, unsigned int ln, char *op)
{
	stack_t *tmp = *head_ref;

	UNUSED(op);
	if (head_ref == NULL || *head_ref == NULL)
		print_error(6, ln);

	*head_ref = tmp->next;
	if (*head_ref)
		(*head_ref)->prev = NULL;

	free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of of the opcode.
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void swap(stack_t **head_ref, unsigned int ln, char *op)
{
	stack_t *tmp;

	UNUSED(op);
	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, "swap");

	tmp = (*head_ref)->next;
	(*head_ref)->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = *head_ref;

	tmp->next = *head_ref;
	(*head_ref)->prev = tmp;
	tmp->prev = NULL;
	*head_ref = tmp;
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of of the opcode (unused parameter).
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void rotl(stack_t **head_ref, unsigned int ln, char *op)
{
	stack_t *tmp;

	UNUSED(op);
	UNUSED(ln);
	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		return;

	tmp = *head_ref;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head_ref;
	(*head_ref)->prev = tmp;
	*head_ref = (*head_ref)->next;
	(*head_ref)->prev->next = NULL;
	(*head_ref)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of of the opcode (unused parameter).
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void rotr(stack_t **head_ref, unsigned int ln, char *op)
{
	stack_t *tmp;

	UNUSED(op);
	UNUSED(ln);
	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		return;

	tmp = *head_ref;

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *head_ref;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head_ref)->prev = tmp;
	(*head_ref) = tmp;
}

/**
 * nop - Does nothing to the stack or queue.
 * @head_ref: pointer to the head pointer of the stack (unused parameter).
 * @ln: the line number of of the opcode (unused parameter).
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void nop(stack_t **head_ref, unsigned int ln, char *op)
{
	UNUSED(head_ref);
	UNUSED(ln);
	UNUSED(op);
}
