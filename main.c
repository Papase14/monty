#include "monty.h"

int main(int argc, char *argv[])
{
	UNUSED(argc);
	stack_t *stack = NULL;
	char *opcode, line[1024];
	unsigned int line_number = 1;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	while (fgets(line, sizeof(line), file))
	{
		opcode = strtok(line, " \t\n");

		/* Check if the opcode is not NULL and not a comment line*/
		if (opcode != NULL && opcode[0] != '#')
		{
			/* Example code for the "push" opcode*/
			if (strcmp(opcode, "push") == 0)
			{
				char *argument = strtok(NULL, " \t\n");
				
				if (argument == NULL || !is_integer(argument))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					fclose(file);
					free(stack);
					return EXIT_FAILURE;
				}
				int value = atoi(argument);
				push(&stack, line_number);
			}
			/* Example code for the "pall" opcode*/
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack);
			}
		} line_number++;
	}
	fclose(file);
	free(stack);
	return 0;
}