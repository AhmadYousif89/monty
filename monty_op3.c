#include "monty.h"

/**
 * print_all - Print all elements on the stack.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: line number of the opcode (unused parameter).
 */
void print_all(stack_t **head_ref, unsigned int ln)
{
	stack_t *temp;

	UNUSED(ln);
	if (head_ref == NULL)
		exit(EXIT_FAILURE);

	temp = *head_ref;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top - Prints the top node of the stack.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of the opcode.
 */
void print_top(stack_t **head_ref, unsigned int ln)
{
	if (head_ref == NULL || *head_ref == NULL)
		print_error(5, ln);

	printf("%d\n", (*head_ref)->n);
}

/**
 * print_char - Prints the Ascii value of the top node (n).
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of the opcode.
 */
void print_char(stack_t **head_ref, unsigned int ln)
{
	int ascii;

	if (head_ref == NULL || *head_ref == NULL)
		print_error(10, ln);

	ascii = (*head_ref)->n;
	if (ascii < 0 || ascii > 127)
		print_error(9, ln);

	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string representation of all elements.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of the opcode (unused parameter).
 */
void print_str(stack_t **head_ref, unsigned int ln)
{
	int ascii;
	stack_t *temp;

	UNUSED(ln);
	if (head_ref == NULL || *head_ref == NULL)
	{
		printf("\n");
		return;
	}

	temp = *head_ref;
	while (temp)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}

	printf("\n");
}
