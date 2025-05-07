// ----------------------------------------------------------------------
// File: overflow.c
//
// Name: Al Shaffer, Paul Clark, John Rolfe
//
// Description: This program generates a user-specified number of large
// random unsigned integers (between 1 and 500,500,500) and stores them
// in a dynamically allocated array. It then prints each value along with
// a running total. If the next value would cause an overflow, it skips
// adding to the total and prints a warning in red.
//
// Syntax:
//     ./overflow number   #number is an int between 1 and 20, inclusive
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

// constants
#define VALID_NUM_ARGS 2
#define ARGV_PROGRAM   0
#define ARGV_NUMBER    1
#define MIN_NUMBER     1
#define MAX_NUMBER     20
#define MAX_VALUE      500500500
#define BASE_10        10
#define CHAR_RED        "\x1b[31m"  /* to set color to red */
#define CHAR_RESET      "\x1b[0m"   /* to reset color to default */

// return codes
#define SUCCESS        0
#define BAD_POINTER    1
#define INVALID_NUMBER 2
#define MALLOC_ERROR   3
#define BAD_INPUT      4


// ----------------------------------------------------------------------
// ------------------------ P R O T O T Y P E S -------------------------
// ----------------------------------------------------------------------
int get_input(int argc, char *argv[], int *num);
int print_values(unsigned int* start, unsigned int num);

// **********************************************************************
// **************************  M  A  I  N  ******************************
// **********************************************************************
int main(int argc, char *argv[])
{
    int num;
    int result                  = SUCCESS;
    unsigned int* ran_numbers   = NULL;

    // Verify the input from the user is valid
    result = get_input(argc, argv, &num);

    // Allocate memory
    if (result == SUCCESS) {                //Check input validation passed
        errno = SUCCESS;
        ran_numbers = calloc(num, sizeof(unsigned int));

        if(ran_numbers == NULL){            //malloc error checking
            if (errno == SUCCESS) {
                printf("Unexpected problem allocating memory.\n");
                result = MALLOC_ERROR;
            } else {
                perror("Memory allocation error");
                result = errno;
            }
        }

        // Generate the requested number of random values and store them in a
        // dynamically allocated array.
        srandom(time(NULL)*getpid());
        for(int i = 0; i<num;i++){
            ran_numbers[i] = (rand() % MAX_VALUE) + 1;
        }

        //Print values 
        result = print_values(ran_numbers, num);

        // Free memory
        free(ran_numbers);
        ran_numbers = NULL;
    }

    return result;
} // end main



// ---------------------------------------------------------------------
// Function:
//     get_input
// Inputs:
//     argc
//         The value passed to main
//     argv
//         The value passed to main
// Outputs:
//     num - pointer to store validated user input
//     function result:
//         An indicator of success or failure. A success is a zero,
//         while a failure is any other value.
// Description:
//     This function verifies that the user provided good input. If so,
//     it returns the integer equivalent of argv[ARGV_NUMBER].
// ---------------------------------------------------------------------
int get_input(int argc, char *argv[], int *num)
{
    char* my_pointer = NULL; //Pointer used for error detection is strtol()

    if (argc != 2) {            //Check number of arguments
        printf("Expected one argument\nExample: ./overflow integer\n");
        return BAD_INPUT;
    }

    errno = 0;
    *num = strtol(argv[1], &my_pointer, BASE_10);

    if (errno != 0) {           //strtol error handling
        perror("Error in converting argument to integer");
        return BAD_INPUT;
    }

    if (*my_pointer != '\0') {  //Check for non numeriacl input
        printf("A non-digit character was encountered in argument: %c\n", *my_pointer);
        return BAD_INPUT;
    }

    if ((*num < MIN_NUMBER) || (*num > MAX_NUMBER)) {   //Check number within bounds
        printf("Requested number must be between %i and %i\n", MIN_NUMBER, MAX_NUMBER);
        return BAD_INPUT;
    }

    return SUCCESS;
} // end get_input


// ---------------------------------------------------------------------
// Function: print_values
//
// Inputs:
//     start - pointer to the array of random values
//     num   - number of values to print
//
// Returns:
//     SUCCESS (0) on completion
//
// Description:
//     Prints a table of random values and their running total,
//     unless adding the next value would overflow.
// ---------------------------------------------------------------------
int print_values(unsigned int* start, unsigned int num){

    if (start == NULL) {
        return BAD_POINTER;
    }

    printf(" Count    Random Value    Running Total\n");        //Print Header
    printf("-----    ------------    -------------\n");

    unsigned int total = 0;
    for(int i = 0; i<num;i++){                                  //Loop through and add
        if(start[i] < (UINT_MAX - total)){                      //Check for overflow
            total += start[i];
            printf("%2i     %12u     %12u\n",i+1,start[i], total);
        }else{
            printf("%2i     %12u     %12u ",i+1,start[i], total);
            printf(CHAR_RED);
            printf("WOULD CAUSE OVERLFOW\n");
            printf(CHAR_RESET);
        }
        
    }
    return EXIT_SUCCESS;
}// end print_values

// end overflow.c
