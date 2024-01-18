#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	validate_args(argc);
	open_monty(argv[1]);
	return (EXIT_SUCCESS);
}
