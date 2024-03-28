#include "main.h"
bus_t bus = {NULL, NULL, NULL, 0};
int main (int argc, char *argv[])
{
    FILE *file;

    if (argc != 1)
    {
        fprintf(stderr, "USAGE: monty file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

return 0;
}