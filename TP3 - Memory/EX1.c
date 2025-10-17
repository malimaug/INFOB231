#include <stdio.h>
#include <stdlib.h>

int main (void) {
    unsigned int* malloc_1 = malloc(4);
    unsigned int* malloc_2 = malloc(4);

    printf("%i et %i\n", malloc_1, malloc_2);
    return EXIT_SUCCESS;
}