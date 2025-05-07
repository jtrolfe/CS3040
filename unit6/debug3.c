#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int *px = NULL;

    errno = 0;
    px = malloc(21474836479999);

    if (px == NULL) {
        printf("malloc failure: %s (%s, line %i)\n",
               strerror(errno), __FILE__, __LINE__);
    }

    return EXIT_SUCCESS;
}
