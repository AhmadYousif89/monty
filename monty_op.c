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
		op_f(&head, ln);
		return;
	}
	/* Handle the "Push" op */
	if (value == NULL)
		print_error(4, ln);
	/* Ignore the (-) sign in values like (-10) */
	if (value[0] == '-')
		value++, flag = -flag;
	/* Check value for none digits */
	for (i = 0; value[i] != '\0'; i++)
		if (isdigit(value[i]) == 0)
			print_error(4, ln);
	/* Create the new node */
	node = create_node(atoi(value) * flag);
	/* Switch insertion mode */
	if (mode == 0)
		add_to_stack(&node, ln);
	if (mode == 1)
		add_to_queue(&node, ln);
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
		{"push", add_to_stack},
		{"pchar", print_char},
		{"pstr", print_str},
		{"pint", print_top},
		{"pall", print_all},
		{"swap", swap},
		{"rotr", rotr},
		{"rotl", rotl},
		{"nop", nop},
		{"pop", pop},
		{"add", add},
		{"div", divid},
		{"mod", modules},
		{"sub", subtract},
		{"mul", multiply},
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
	/* Unkonwn opcode */
	if (is_error)
		print_error(2, ln, opcode);
}
