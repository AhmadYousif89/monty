#include "monty.h"

/**
 * run_monty_op - Run the required function.
 * @op_f: Pointer to the required function.
 * @op: string representing the operation code.
 * @value: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @mode: insertion mode. 0 = stack, 1 = queue.
 */
void run_monty_op(op_func op_f, char *op, char *value, int ln, int mode)
{
	int i = 0, flag = 1;
	stack_t *node;

	/* Run all operations execpt the "Push" op */
	if (strcmp(op, "push") != 0)
	{
		op_f(&head, ln, op);
		return;
	}
	/* Handle the "Push" op */
	if (value == NULL)
		print_error(4, ln);

	if (value[0] == '-')
		value++, flag = -flag;

	for (i = 0; value[i] != '\0'; i++)
		if (isdigit(value[i]) == 0)
			print_error(4, ln);

	node = create_node(atoi(value) * flag);
	/* Switch insertion mode */
	if (mode == 0)
		add_to_stack(&node, ln, op);
	if (mode == 1)
		add_to_queue(&node, ln, op);
}

/**
 * get_op - Get the required function for the corresponding opcode
 * @opcode: operation code
 * @value: argument of opcode "Push"
 * @mode: insertion mode. 0 = stack, 1 = queue.
 * @ln: line numeber for the operation.
 */
void get_op(char *opcode, char *value, int ln, int mode)
{
	int i = 0, is_error = 1;
	instruction_t op_list[] = {
		{"pint", print_top},
		{"pall", print_all},
		{"pstr", print_str},
		{"pchar", print_char},
		{"prevs", print_str_reverse},
		{"push", add_to_stack},
		{"swap", swap},
		{"rotr", rotr},
		{"rotl", rotl},
		{"add", calc},
		{"div", calc},
		{"mod", calc},
		{"sub", calc},
		{"mul", calc},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL}};

	/* Handle comments */
	if (opcode[0] == '#' || (opcode[0] == '/' && opcode[1] == '/'))
		return;

	for (i = 0; op_list[i].opcode; i++)
		if (strcmp(opcode, op_list[i].opcode) == 0)
		{
			run_monty_op(op_list[i].f, opcode, value, ln, mode);
			is_error = 0;
			break; /* Exit loop on match */
		}

	if (is_error) /* Unkonwn opcode */
		print_error(2, ln, opcode);
}
