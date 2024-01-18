#include "monty.h"

/**
 * validate_args - validate the count of args passsed to the program
 * @argc: number of arguments
 */
void validate_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_monty - Open the monty bytecode file
 * @file_name: the file to work with
 */
void open_monty(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		print_error(1, file_name);

	read_monty(fd);
	fclose(fd);
	free_stack();
}

/**
 * read_monty - Read from the monty bytecode file
 * @fd: pointer to file descriptor
 */
void read_monty(FILE *fd)
{
	size_t len = 0;
	char *buffer = NULL;
	int line_number = 1, mode = 0;

	while (getline(&buffer, &len, fd) != -1)
		mode = parse_line(buffer, line_number++, mode);

	free(buffer);
}

/**
 * parse_line - Handle the monty file line by line
 * @buffer: line from the monty file
 * @ln: the instruction line number
 * @mode: insert mode. 0 = stack, 1 = queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *buffer, int ln, int mode)
{
	char *opcode, *value;
	const char *delim = "\n \t";

	if (buffer == NULL)
		print_error(3);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (mode);

	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	value = strtok(NULL, delim);
	get_op(opcode, value, ln, mode);

	return (mode);
}
