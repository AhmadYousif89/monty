#include "monty.h"

/**
 * create_node - Creates a new node.
 * @n: the node's (n) value.
 * Return: pointer to the new node or NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		print_error(3);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: the line number of the opcode (unused parameter).
 */
void add_to_stack(stack_t **new_node, unsigned int ln)
{
	stack_t *temp;

	UNUSED(ln);
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode (unused parameter).
 */
void add_to_queue(stack_t **new_node, unsigned int ln)
{
	stack_t *temp;

	UNUSED(ln);
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	temp = head;
	while (temp->next)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}

/**
 * free_stack - Frees nodes in the stack.
 */
void free_stack(void)
{
	stack_t *temp = head, *next;

	if (temp == NULL)
		return;

	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
