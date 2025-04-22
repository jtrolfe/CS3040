#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BYTES 20

int main(void)
{
    char *ptr = NULL;

    ptr = malloc(NUM_BYTES);

    strncpy(ptr, "hello world", NUM_BYTES);    // write to memory

    printf("%s\n", ptr);

    free(ptr);

    strncpy(ptr, "hi world", NUM_BYTES); // write memory after freeing
    printf("%s\n", ptr);                 // read memory after freeing

    return EXIT_SUCCESS;
}
