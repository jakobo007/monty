#include "main.h"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    open_file(argv[1]);
    free_stack(&stack);
    
    return (0);
}