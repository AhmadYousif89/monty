#include "monty.h"

/**
 * calc - Perform arithmatic operations based on opcode
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: line number of the opcode.
 * @op: pointer to the string containing the opcode.
 */
void calc(stack_t **head_ref, unsigned int ln, char *op)
{
	int result = 0;

	if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL)
		print_error(7, ln, op);

	(*head_ref) = (*head_ref)->next;

	if (strcmp(op, "add") == 0)
		result = (*head_ref)->n + (*head_ref)->prev->n;

	if (strcmp(op, "sub") == 0)
		result = (*head_ref)->n - (*head_ref)->prev->n;

	if (strcmp(op, "mul") == 0)
		result = (*head_ref)->n * (*head_ref)->prev->n;

	if (strcmp(op, "div") == 0)
	{
		if ((*head_ref)->prev->n == 0)
			print_error(8, ln);
		result = (*head_ref)->n / (*head_ref)->prev->n;
	}

	if (strcmp(op, "mod") == 0)
	{
		if ((*head_ref)->prev->n == 0)
			print_error(8, ln);
		result = (*head_ref)->n % (*head_ref)->prev->n;
	}

	(*head_ref)->n = result;
	free((*head_ref)->prev);
	(*head_ref)->prev = NULL;
}

/**
 * print_all - Print all elements on the stack.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: line number of the opcode (unused parameter).
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void print_all(stack_t **head_ref, unsigned int ln, char *op)
{
	stack_t *temp;

	UNUSED(ln);
	UNUSED(op);
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
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void print_top(stack_t **head_ref, unsigned int ln, char *op)
{
	UNUSED(op);
	if (head_ref == NULL || *head_ref == NULL)
		print_error(5, ln);

	printf("%d\n", (*head_ref)->n);
}

/**
 * print_char - Prints the Ascii value of the top node (n).
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of the opcode.
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void print_char(stack_t **head_ref, unsigned int ln, char *op)
{
	int ascii;

	UNUSED(op);
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
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void print_str(stack_t **head_ref, unsigned int ln, char *op)
{
	int ascii;
	stack_t *temp;

	UNUSED(op);
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

/**
 * print_str_reverse - Prints a string representation of all elements.
 * @head_ref: pointer to the head pointer of the stack.
 * @ln: the line number of the opcode (unused parameter).
 * @op: pointer to the string containing the opcode (unused parameter).
 */
void print_str_reverse(stack_t **head_ref, unsigned int ln, char *op)
{
	int i, length = 0, ascii = 0;
	char *str;
	stack_t *temp;

	UNUSED(op);
	if (head_ref == NULL || *head_ref == NULL)
	{
		printf("\n");
		return;
	}

	temp = *head_ref;
	while (temp)
	{
		ascii = temp->n;
		if (ascii > 0 && ascii <= 127)
			length++;
		else
			break;
		temp = temp->next;
	}

	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		print_error(3, ln);

	temp = *head_ref;
	while (temp)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		*str++ = (char)ascii;
		temp = temp->next;
	}
	*str = '\0';
	str -= length;

	for (i = length - 1; i >= 0; i--)
		printf("%c", str[i]);

	printf("\n");
}
