#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILD_PID 0

int main(void)
{
    pid_t pid;

    printf("Parent pid is %d\n", getpid());
    printf("Parent about to fork...\n");
    fflush(stdout);

    // Create a child process
    errno = 0;
    pid = fork();
    if (pid == CHILD_PID) {
        printf("Child is running now with pid %d\n", getpid());
        fflush(stdout);
    } else if (pid > CHILD_PID) {
        printf("Parent is running: child pid is %d\n", pid);
        fflush(stdout);
    } else {   //pid < CHILD_PID
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    printf("Process with PID %d exiting...\n", getpid());

    // bad practice to not find out how child did -- more later

    fflush(stderr);
    fflush(stdout);
    return EXIT_SUCCESS;
}
