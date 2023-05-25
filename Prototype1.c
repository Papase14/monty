#include "monty.h"

/**
  * push - push data to top of stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	if (new_node != NULL)
	{
		new_node->n = argument;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (*stack == NULL)
			*stack = new_node;
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			*stack = new_node;
		}
	}
	else
	{
		free_dlist(*stack);
		free(new_node);
		err(4);
	}
}

/**
  * pall - prints all arguments inserted.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
