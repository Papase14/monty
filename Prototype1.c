#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(argument[0]) && argument[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

bool is_integer(const char *str, int *result)
{
	char *endptr;
	int value = strtol(str, &endptr, 10);
	if (str == NULL || *str == '\0') {
		return false;
	}

	if (*endptr != '\0') {
		return false;
	}

	if (result != NULL) {
		*result = value;
	}
	return true;
}

