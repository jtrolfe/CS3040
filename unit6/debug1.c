#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned int i;

#ifdef DEBUG
    printf("argc = %d\n", argc);
#endif

    for (i=0; i<argc; ++i) {
        // Print out each argument in argv
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
