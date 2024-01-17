#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @n_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void insert_stack(stack_t **n_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temper;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (header == NULL)
	{
		header = *n_node;
		return;
	}
	temper = header;
	header = *n_node;
	header->next = temper;
	temper->prev = header;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *temper;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temper = *stack;
	while (temper != NULL)
	{
		printf("%d\n", temper->n);
		temper = temper->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_max(stack_t **stack, unsigned int line_number)
{
	stack_t *temper;

	if (stack == NULL || *stack == NULL)
		error_2(7, line_number);

	temper = *stack;
	*stack = temper->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temper);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_2(6, line_number);
	printf("%d\n", (*stack)->n);
}