#include "main.h"

void open_file(const char *filename)
{
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    process_command(file);
    fclose(file);
}