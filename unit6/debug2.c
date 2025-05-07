#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef DEBUG
// Replace all malloc calls with this malloc/printf combination
#define malloc(a)  \
        malloc(a); \
        printf("malloc requested %li bytes\n", a);
#endif

int main(void) {
    int *px = NULL;

    errno = 0;
    px = malloc(sizeof(int));

    if (errno != 0) {
        perror("malloc error occured");
    } else {
        printf("malloc succeeded\n");
    }

    *px = 42;

    free(px);
    px = NULL;

    return EXIT_SUCCESS;
}
