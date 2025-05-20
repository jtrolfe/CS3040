#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

// Function for handling signals
void signal_handler (int signal) {
    if (signal == SIGINT) {
        // User opressed Ctrl-c
        printf(": User entered Ctrl-c.\n");
    } else if (signal == SIGTSTP) {
        // User opressed Ctrl-z
        printf(": User entered Ctrl-z.\n");
    }
}

int main(void)
{
    int result = EXIT_SUCCESS;
    struct sigaction act;
    int rval;

    // Prepare signal action settings
    act.sa_handler = signal_handler;
    sigfillset(&act.sa_mask);   //mask all signals, exc. STOP/KILL
    act.sa_flags = SA_RESTART;

    //Register handler for interrupt signal
    errno = 0;
    rval = sigaction(SIGINT, &act, NULL);
    if (rval != 0) {
        fprintf(stderr, "Unable to pass interrupt signal: %s\n",
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    //Register handler for terminal stop signal
    errno = 0;
    rval = sigaction(SIGTSTP, &act, NULL);
    if (rval != 0) {
        fprintf(stderr, "Unable to pass term. stop signal: %s\n",
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Pause process for user input...
    printf("Press Ctrl-c or Ctrl-z to test signal handling\n");
    printf("Press CR to continue\n");
    fflush(stdout);
    getc(stdin);

    fflush(stderr);
    fflush(stdout);
    return result;
}
