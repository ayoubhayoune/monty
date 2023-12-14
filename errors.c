#include "monty.h"

/**
 * handleGeneralErrors - Prints error messages determined by their error code.
 * @errorCode: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for the operation.
 */
void handleGeneralErrors(int errorCode, ...)
{
	va_list args;
	char *instruction;
	int lineNumber;

	va_start(args, errorCode);
	if (errorCode == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (errorCode == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	}
	else if (errorCode == 3)
	{
		lineNumber = va_arg(args, int);
		instruction = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, instruction);
	}
	else if (errorCode == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (errorCode == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	}
	va_end(args);

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handleMoreErrors - Handles errors.
 * @errorCode: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for the operation.
 * (9) => Division by zero.
 */
void handleMoreErrors(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNumber;

	va_start(args, errorCode);
	if (errorCode == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	}
	else if (errorCode == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	}
	else if (errorCode == 8)
	{
		lineNumber = va_arg(args, unsigned int);
		operation = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, operation);
	}
	else if (errorCode == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	}
	va_end(args);

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handleStringErrors - Handles errors.
 * @errorCode: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void handleStringErrors(int errorCode, ...)
{
	va_list args;
	int lineNumber;

	va_start(args, errorCode);
	lineNumber = va_arg(args, int);
	if (errorCode == 10)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
	}
	else if (errorCode == 11)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
	}
	va_end(args);

	free_nodes();
	exit(EXIT_FAILURE);
}
