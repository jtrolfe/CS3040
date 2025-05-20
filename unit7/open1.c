#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define LOWEST_FD 0

int main(int argc, char *argv[])
{
    int fd = LOWEST_FD;

    // Try to open password file with R/W access
    printf("---------------------------------------------------\n");

    errno = 0;
    fd = open("/etc/passwd", O_RDWR);
    if (fd < LOWEST_FD) {
        perror("Error: tried to open /etc/passwd with R/W access");
    } else {
        printf("Success: opened /etc/passwd with R/W access.\n");
        close(fd);
    }

    // Try to open password file with R/O access
    printf("---------------------------------------------------\n");
    errno = 0;
    fd = open("/etc/passwd", O_RDONLY);
    if (fd < LOWEST_FD) {
        perror("Error: tried to open /etc/passwd with R/O access");
    } else {
        printf("Success: opened /etc/passwd with R/O access.\n");
        close(fd);
    }

    printf("---------------------------------------------------\n");
    return EXIT_SUCCESS;
}
