#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SUCCESS 0

int main(int argc, char *argv[])
{
    struct rlimit resource;

    errno = SUCCESS;
    getrlimit(RLIMIT_NOFILE, &resource);

    if (errno != SUCCESS) {
        perror("Error: unable to get file limits");
        exit(EXIT_FAILURE);
    } else {
        printf("Hard limit = %u\n", (unsigned)resource.rlim_max);
        printf("Soft limit = %u\n", (unsigned)resource.rlim_cur);
    }

    return EXIT_SUCCESS;
}
