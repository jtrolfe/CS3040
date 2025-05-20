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

    printf("Will try to open '%s'...\n", MYFILE);
    errno = 0;
    fd = open(MYFILE, O_RDONLY);
    if (fd < LOWEST_FD) {
        perror("Unexpected error opening file");
        exit(EXIT_FAILURE);
    }

    printf("------\n");

    errno = 0;
    close(fd);
    perror("closed fd");
    close(fd);         // this 2nd close should fail
    perror("closed fd again");

    return EXIT_SUCCESS;
}
