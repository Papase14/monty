#include "monty.h"

/**
  * main - entry point.
  * @argc: argument count.
  * @argv: argument vector.
  *
  * Return: 0.
  */
int main(int argc, char **argv)
{
	FILE *file;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char **tk = NULL, *line = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		err(1);
	file = fopen(argv[1], "r");
	if (file == NULL)
		err(2, argv[1]);

	while (getline(&line, &size, file) != -1)
	{
		if (!strcmp(line, "\n") || *line == '#')
		{
			line_number++;
			continue;
		}
		tk = break_line(line), op_func = get_opcode(tk[0]);
		if (op_func == NULL)
			free_dlist(stack), err(3, line_number, tk[0], tk, line);
		if (strcmp(tk[0], "push") == 0 && tk[1])
		{
			if (toInt(tk[1]) >= 0)
				argument = toInt(tk[1]);
			else
			{
				free(line), free(tk), fclose(file), free_dlist(stack);
				err(5, line_number);
			}
		}
		if (!strcmp(tk[0], "push") && !tk[1])
			free(line), free(tk), fclose(file), free_dlist(stack), err(5, line_number);

		op_func(&stack, line_number), line_number++, free(tk);
	}
	fclose(file), free(line), free_dlist(stack);	
	return (0);
}