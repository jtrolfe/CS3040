#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILD_PID 0

int main(void)
{
    int pid;
    int result = EXIT_SUCCESS;

    errno = 0;
    pid = fork();
    if (pid == CHILD_PID) {
        // the child -- will list current directory
        printf("\nChild is running now with pid %d\n", getpid());
        printf("Child is about to exec 'ls'\n");
        fflush(stdout);
        errno = 0;
        result = execlp("ls", "ls", NULL);

        // there's no need to check for error condition (why?)
        perror("execlp failed");
        fprintf(stderr,"If you got here, things didn't go well\n");
        exit(EXIT_FAILURE);
    } else if (pid > CHILD_PID) {
        // the parent -- pause so zombie state of child can be seen
        printf("Press CR to continue\n");
        fflush(stdout);
        getc(stdin);
    } else {
        // fork error -- still in parent
        perror("fork failed");
        result = EXIT_FAILURE;
    }

    // bad practice to not find out how child did -- more later

    fflush(stderr);
    fflush(stdout);
    return result;
}
