#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MYFILE "/etc/passwd"
#define LOWEST_FD 0

int main(int argc, char *argv[])
{
    int fd = LOWEST_FD;
    close(0);

    printf("Will try to open '%s' read-only...\n", MYFILE);
    errno = 0;
    fd = open(MYFILE, O_RDONLY);
    if (fd < LOWEST_FD) {
        perror("Unexpected error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Success: file descriptor = %d\n", fd);

    close(fd);

    return EXIT_SUCCESS;
}
