#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> // needed for strerror

#define BYTES_TO_REQUEST 214748364799u

int main(int argc, char *argv[])
{
    char *ptr = NULL;

    errno = 0;
    ptr = malloc(BYTES_TO_REQUEST);
    if (ptr==NULL) {
        // An example of using the #define listed in the man page:
        printf("errno returned %i", errno);
        if (errno == ENOMEM) {
            printf(" (out of memory)\n");
        } else {
            printf("\n");
        }

        // An example using strerror, which is not quite the same
        // as perror, as we shall see when we talk about the
        // difference between stdout and stderr:
        printf("Unable to malloc %lu bytes: %s\n",
               BYTES_TO_REQUEST,
               strerror(errno));
    } else {
        // should not get here because we asked for too much.
        printf("malloc worked\n");
    }

    return EXIT_SUCCESS;
}
