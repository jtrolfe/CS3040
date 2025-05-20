#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NO_OPTIONS 0
#define CHILD_PID  0

int main(void)
{
    int pid;
    int status = EXIT_SUCCESS;

    pid = fork();
    if (pid == CHILD_PID) {
        // the child -- about to list the directory
        printf("In child, about to exec 'ls'...\n");
        errno = 0;
        status = execlp("ls", "ls", "-l", NULL);

        perror("exec failed");
        fprintf(stderr,"If you got here, things didn't go well.\n");
        exit(EXIT_FAILURE);

    }  else if (pid > CHILD_PID) {
        // the parent -- wait for child to finish
        errno = 0;
        pid = waitpid(pid, &status, NO_OPTIONS);
        //pid = wait(&status);    //simpler version

        if (errno != 0) {
            perror("Unable to wait on child.");
            status = EXIT_FAILURE;
        } else if (WIFEXITED(status)) {
            printf("Parent: the child has terminated. "
                   "Result was %d.\n",
                   WEXITSTATUS(status));
        }

    } else {
        // fork error -- still in parent
        perror("fork failed");
        status = EXIT_FAILURE;
    }

    fflush(stdout);
    fflush(stderr);
    return status;
}
