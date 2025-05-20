#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MYFILE "newfile"
#define LOWEST_FD 0

int main(int argc, char *argv[])
{
    int fd = LOWEST_FD;

    // Try to open password file with R/W access
    printf("---------------------------------------------------\n");

    errno = 0;
    fd = open(MYFILE, O_RDWR| O_CREAT, S_IWUSR| S_IRUSR| S_IRGRP| S_IROTH);
    if (fd < LOWEST_FD) {
        perror("Error: tried to open file with R/W access");
        exit(EXIT_FAILURE);
    } else {
        printf("Success: created %s with R/W access.\n", MYFILE);
        close(fd);
    }

    printf("---------------------------------------------------\n");
    return EXIT_SUCCESS;
}
