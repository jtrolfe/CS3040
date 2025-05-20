#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define INPUT_FILE "/etc/passwd"
#define BUFSIZE 128
#define SUCCESS 0

int main(int argc, char *argv[])
{
    char buf[BUFSIZE];    // Until used we'll get a compiler warning.
    FILE *fstream = NULL;
    size_t num;
    int result = EXIT_SUCCESS;

    // Open the file
    errno = SUCCESS;
    fstream = fopen(INPUT_FILE, "r");
    if (fstream == NULL) {
        fprintf(stderr, "Unable to open '%s': %s\n",
                INPUT_FILE, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Code goes here to read and display
    // the file using the declared buffer

    // clean up
    if (fstream != NULL) {
        fclose(fstream);
        fstream = NULL;
    }

    fflush(stdout);

    return result;
}
