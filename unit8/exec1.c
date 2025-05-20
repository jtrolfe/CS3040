#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILD_PID 0

int main(void)
{
    pid_t pid;
    int   result;

    errno = 0;
    pid = fork();
    if (pid == CHILD_PID) {
        // the child process
        printf("\nChild is running now with pid %d\n", getpid());
        printf("Child is about to exec 'ls -l'\n");
        fflush(stdout);

        errno = 0;
        result = execlp("ls", "ls", "-l", NULL);
        if ((result != 0) || (errno != 0)) {
            perror("exec failed");
        }

        fprintf(stderr,"If you got here, things didn't go well\n");  //Why??
        exit(EXIT_FAILURE);

    } else if (pid > CHILD_PID) {
        printf("Parent now exiting.\n");
    } else {  //pid < CHILD_PID
        perror("fork error");
    }

    // bad practice to not find out how child did -- more later

    fflush(stderr);
    fflush(stdout);
    return EXIT_SUCCESS;
}
