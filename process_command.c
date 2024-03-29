#include "main.h"

void process_command(FILE *file)
{
    char line[STACK_SIZE];
    char *token;
    unsigned int line_number = 0;
    int value; 

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        token = strtok(line, " \t\n");
        if (token == NULL || token[0] == '#')
        {
            continue;
        }

        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (token == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            value = atoi(token);
            push(&stack, value);
        }

        else if (strcmp(token, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(token, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(token, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }
}
