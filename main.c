#include "main.h"
bus_t bus = {NULL, NULL, NULL, 0};
int main (int argc, char *argv[])
{
    FILE *file;
    size_t size = 0;
    ssize_t read_line_data = 1;
    stack_t *stack = NULL;
    char *line_content;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line_data > 0)
    {
        line_content = NULL;
        read_line_data = getline(&line_content, &size, file);
        bus.line_content = line_content;
        counter++;

        if (read_line_data > 0)
        {
            execute(line_content, &stack, counter, file);
        }
        free(line_content);
    }

    free_stack(stack);
    fclose(file);
    
return (0);
}