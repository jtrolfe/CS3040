// ------------------------------------------------------
// File: dots.c
//
// Name: John Rolfe
//
// Description: This program will draw the number of dots
// specified on the terminal screen. Number of dots is 
// limited to between 1 and 100 dots.
//
// Syntax:
// Expected input: ./dots integer(1-100)
// Example: ./dots 6
// Test
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
#define MOVE_CURSOR "\x1b[%i;%iH"
#define NUMBER_BASE 10
#define MAX_DOTS 100

void display_dots(const long int number){
    int result = 0;
    int max_rows = 0;
    int max_cols = 0;
    struct winsize win;

    // Get info about the current window size. C
    errno = 0;
    result = ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
    if ((result < 0) || (errno != 0)){
        printf("An error occured interacting with the current console window\n");
    }
    max_rows = win.ws_row;
    max_cols = win.ws_col;

    sleep(1);

    //Loop through and draw the required number of dots
    printf(CLEAR_SCREEN);
    for(int i = 0; i<number;i++){
        int temprow = (int)(random()%(max_rows-1) +1);  //Generate random number between 1 and (#rows -1)
        int tempcol = (int)(random()%(max_cols)+1);     //Generate random number between 1 and #cols
        printf(MOVE_CURSOR, temprow, tempcol);
        printf("*");
        fflush(stdout);
        sleep(1);                                       //Pause for 1 second
    }

    //Return cursor to bottom row
    printf(MOVE_CURSOR, max_rows,1);;
    
}

// Function to check the number of arguments and ensure an 
// integer was passed in as the argument
int check_inputs(int argument_number, char* argument_array[]){
    int num;
    char* my_pointer = NULL;
    if(argument_number != 2){
        printf("Expected one argument\nExample ./dots integer\n");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    num = strtol(argument_array[1],&my_pointer,NUMBER_BASE);
    if(errno != 0){
        printf("Error in converting argument to integer\nERROR #: %i\n", errno);
        exit(EXIT_FAILURE);
    }

    if(num <= 0 || num >MAX_DOTS){
        printf("Requested number of dots must be between 1 and 100\n");
        exit(EXIT_FAILURE);
    }
    
    if(*my_pointer != '\0'){
        printf("A non digit character was encountered in argument: %c\n", *my_pointer);
        exit(EXIT_FAILURE);
    }
    return num;
}

int main(int argc, char* argv[]){


    int num_dots = check_inputs(argc, argv);

    //Seed random number
    srandom(time(NULL) * getpid());

    //Display Dots
    display_dots(num_dots);


    return 0;
}