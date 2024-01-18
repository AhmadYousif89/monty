#include "monty.h"

/**
 * print_error - Print error messages according to their error code
 * @error_code: the error code number.
 */
void print_error(int error_code, ...)
{
	va_list ag;
	int ln;

	va_start(ag, error_code);
	if (error_code == 1)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	if (error_code == 2)
	{
		ln = va_arg(ag, int);
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, va_arg(ag, char *));
	}
	if (error_code == 3)
		fprintf(stderr, "Error: malloc failed\n");
	if (error_code == 4)
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
	if (error_code == 5)
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	if (error_code == 6)
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	if (error_code == 7)
	{
		ln = va_arg(ag, unsigned int);
		fprintf(stderr, "L%d: can't %s, stack too short\n", ln, va_arg(ag, char *));
	}
	if (error_code == 8)
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	if (error_code == 9)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(ag, int));
	if (error_code == 10)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(ag, int));

	free_stack();
	exit(EXIT_FAILURE);
}
