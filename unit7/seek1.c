#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define LOWEST_FD 0
#define BUFSIZE   64
#define NUM_TURNS 5

int main(int argc, char *argv[])
{
    int fd = LOWEST_FD;
    char buf[BUFSIZE];
    int out = 1;
    int i;

    errno = 0;
    fd = open("/etc/passwd", O_RDONLY);
    if ((fd < LOWEST_FD) || (errno != EXIT_SUCCESS)) {
        perror("Error: tried to open /etc/passwd with R/O access");
        exit(EXIT_FAILURE);
    } else {
        for (i = 0; i < NUM_TURNS; ++i) {
            lseek(fd, 0, SEEK_SET);  // move to start of file
//            lseek(fd, 0, SEEK_CUR);  // move to next position in file
//            lseek(fd, 0, SEEK_END);  // move to end of file
            out = read(fd, buf, BUFSIZE);
            if (out > 0) {
                buf[out] = '\0';
                printf("%s\n", buf);
                printf("-------\n");
            }
        }

        errno = 0;
        close(fd);
        perror("closed fd");
    }

    return EXIT_SUCCESS;
}
