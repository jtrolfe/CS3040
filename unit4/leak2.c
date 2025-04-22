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

    printf("%s\n", ptr);  // read from memory after freeing it

    return EXIT_SUCCESS;
}
