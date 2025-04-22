#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BYTES 20

int main(void)
{
    char *ptr = NULL;

    *ptr = 42;  // This should crash the program

    return EXIT_SUCCESS;
}
