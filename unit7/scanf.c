#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define BUF_SIZE 128

int main(int argc, char *argv[])
{
    int user_number = 0;
    int num_items;
    char buffer[BUF_SIZE];

    printf("Enter ^D when you are done.\n");    // ^D == EOF
    fflush(stdout);

    // Get a number from a user using scanf, and print back out.
    while (true) {
        // prompt for and get a number from the user
        printf("\nEnter a number: ");
        fflush(stdout);
        errno = 0;
        num_items = scanf("%i", &user_number);

        // Try to handle the various situations
        if (errno != 0) {
            perror("Input error");
            clearerr(stdin);
        } else if (feof(stdin)) {
            // ^D was entered
            printf("\nInput session is over\n");
            break;
        } else if (num_items == 0) {
            // A non-integer string is in the input buffer,
            // and it needs to be cleaned out.
            fgets(buffer, BUF_SIZE, stdin);
            buffer[strlen(buffer)-1] = '\0';
            fprintf(stderr, "'%s' is not an integer.\n", buffer);
        } else {
            // display the number we got
            printf("The number you entered was %i\n", user_number);
        }
    }

    return EXIT_SUCCESS;
}
