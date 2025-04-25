// ------------------------------------------------------
// File: dots.c
//
// Name: John Rolfe
//
// Description: This program will clear the screen and 
// draw the number of dots specified on the terminal 
// screen. Number of dots is limited to between 1 and 
// 100 dots.
//
// Syntax:
//     Expected input: ./dots integer(1-100)
//     Example: ./dots 6
// ------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define CLEAR_SCREEN "\x1b[2J"
#define MOVE_CURSOR  "\x1b[%i;%iH"
#define NUMBER_BASE  10
#define MAX_DOTS     100
#define SLEEP_TIME   1

/**
 * Function: display_dots
 * -----------------------
 * Clears the terminal screen and draws a specified number of
 * asterisks (*) at random locations.
 *
 * number: the number of dots to display (1 to 100)
 *
 * returns: void
 */
void display_dots(const long int number)
{
    int result     = 0;
    int max_rows   = 0;
    int max_cols   = 0;
    struct winsize win;

    // Get terminal window size
    errno = 0;
    result = ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
    if ((result < 0) || (errno != 0)) {
        printf("An error occurred interacting with the current console window\n");
    }

    max_rows = win.ws_row;
    max_cols = win.ws_col;

    // Clear screen and print dots in random locations
    printf(CLEAR_SCREEN);
    for (int i = 0; i < number; i++) {
        int temprow = (int)(random() % (max_rows - 1) + 1);   // Row range: 1 to max_rows - 1
        int tempcol = (int)(random() % max_cols + 1);         // Col range: 1 to max_cols

        printf(MOVE_CURSOR, temprow, tempcol);                // Move cursor to random location
        printf("*");                                          // Print dot
        fflush(stdout);
        sleep(SLEEP_TIME);                                    // Delay for 1 second
    }

    // Move cursor to bottom-left of the screen
    printf(MOVE_CURSOR, max_rows, 1);
}

/**
 * Function: check_inputs
 * ----------------------
 * Verifies program arguments and converts input to an integer.
 * Ensures input is a valid integer within 1–100.
 *
 * argument_number: count of command-line arguments
 * argument_array:  array of command-line arguments
 *
 * returns: validated integer between 1 and 100
 */
int check_inputs(int argument_number, char* argument_array[])
{
    int num;
    char* my_pointer = NULL;

    if (argument_number != 2) {
        printf("Expected one argument\nExample: ./dots integer\n");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    num = strtol(argument_array[1], &my_pointer, NUMBER_BASE);
    if (errno != 0) {
        printf("Error in converting argument to integer\nERROR #: %i\n", errno);
        exit(EXIT_FAILURE);
    }

    if (num <= 0 || num > MAX_DOTS) {
        printf("Requested number of dots must be between 1 and 100\n");
        exit(EXIT_FAILURE);
    }

    if (*my_pointer != '\0') {
        printf("A non-digit character was encountered in argument: %c\n", *my_pointer);
        exit(EXIT_FAILURE);
    }

    return num;
}

/**
 * Function: main
 * --------------
 * Entry point for the program. Verifies input, seeds random
 * number generator, and displays dots.
 *
 * returns: 0 upon successful completion
 */
int main(int argc, char* argv[])
{
    int num_dots = check_inputs(argc, argv);        // Validate and parse input
    srandom(time(NULL) * getpid());                 // Seed random number generator
    display_dots(num_dots);                         // Display the dots

    return 0;
}
