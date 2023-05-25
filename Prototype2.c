#include "monty.h"

/**
 * pint - print the top of the stack
 * @stack: stack of the memory
 * @line_num: line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	} printf("%d\n", (*stack)->n);
}

/**
 * pop - pop the node from memory
 * @stack: stack of the memory
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	free(*stack);
	*stack = next;

	if (*stack == NULL)
		return;

    (*stack)->prev = NULL;
}

/**
 * swap - swap top 2 numbers
 * @stack: input stack address
 * @line_num: current line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int holder = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	holder = current->n;
	current->n = holder;
	current->n = current->next->n;
	current->next->n = holder;
}

/**
 * add - adding first two elements
 * @stack: input stack address
 * @line_num: current line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	total = current->n + current->next->n;
	pop(stack, line_num);
	(*stack)->n = total;
}

/**
 * nop - does nothing
 * @stack: input stack address
 * @line_num: current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}