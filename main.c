#include "monty.h"

int main(int argc, char *argv[])
{
    // ...

    stack_t *stack = NULL;
    char *opcode, *argument;
    unsigned int line_number = 1;

    while (fgets(line, sizeof(line), file))
    {
        opcode = strtok(line, " \t\n");

        // Check if the opcode is not NULL and not a comment line
        if (opcode != NULL && opcode[0] != '#')
        {
            // Add code here to handle the specific opcodes

            // Example code for the "push" opcode
            if (strcmp(opcode, "push") == 0)
            {
                push(&stack, line_number);
            }
            // Example code for the "pall" opcode
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }

            // Add more opcode cases here...
        }

        line_number++;
    }

    // ...

    return EXIT_SUCCESS;
}
