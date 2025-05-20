#include <stdio.h>
#include <stdlib.h>

void cleanup1(void)
{
    printf("cleanup1() invoked\n");
    fflush(stdout);
}


void cleanup2(void)
{
    printf("cleanup2() invoked\n");
    fflush(stdout);
}


int main(void)
{
    int result;

    printf("About to register 'cleanup1()'\n");
    result = atexit(cleanup1);
    if (result != 0) {
        fprintf(stderr, "atexit failed with cleanup1()\n");
    } else {
        printf("About to register 'cleanup2()'\n");
        result = atexit(cleanup2);
        if (result != 0) {
            fprintf(stderr,"atexit failed with cleanup2()\n");
        }
    }

    printf("About to exit...\n");
    fflush(stdout);
    fflush(stderr);

    return EXIT_SUCCESS;
}
