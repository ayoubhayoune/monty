#include "monty.h"

/**
 * addToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addToStack(stack_t **newNode, __attribute__((unused))
		unsigned int lineNumber)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *newNode;
		return;
	}

	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * printStackElements - Prints the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printStackElements(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	temp = *stack;
	for (; temp != NULL; temp = temp->next)
	{
		printf("%d\n", temp->n);
	}
}

/**
 * removeTopNode - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void removeTopNode(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, lineNumber);

	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * printTopElement - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printTopElement(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, lineNumber);

	printf("%d\n", (*stack)->n);
}
