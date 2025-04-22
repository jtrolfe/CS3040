#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char *argv[])
{
    char *ptr = NULL;

    errno = 0;
    ptr = malloc(2147483647);

    if ((ptr == NULL) || (errno != 0)) {
        perror("malloc error");
    } else {
        printf("malloc worked = %li bytes\n", malloc_usable_size(ptr));
    }

    return EXIT_SUCCESS;
}
