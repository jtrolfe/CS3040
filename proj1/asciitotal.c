/*
1. verify number of arguments

2. convert arguments into numbers 
    use errno, strlen(does not set errno), 
    loop through argv[2] test if isdigit
    use strtolon(does set errno)
    verify number is within bounds (1-100)

3. convert argv[1] to a numerical value using ascii codes
    use a loop

*/

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<ctype.h>

#define BASE 10
#define NUM_ARGS 2

int main(int argc, char *argv[]){
    //Local varialbles
    char    in_string[50];
    int     in_int;
    int     total   =0;

    //Verify correct number of arguments
    if(argc != (NUM_ARGS+1)){
        printf("Expected two arguments.\nExpected input: asciitotal string integer(1-100)\n");
        exit(EXIT_FAILURE);
    }

    //Get input string
    for(int i =0; i<strlen(argv[1]);i++){
        in_string[i] = argv[1][i];
        total = total + in_string[i];
    }

    //Get input integer
    for(int i =0; i<strlen(argv[2]);i++){
        if(!isdigit(argv[2][i])){
            printf("Encountered non digit element of second argument.\nExpected input: asciitotal string integer(1-100)\n");
            exit(EXIT_FAILURE);
        }
    }

    in_int = strtol(argv[2],NULL,10);
    if(in_int<1 || in_int > 100){ //Check bounds of integer value
        printf("Second argument must be an integer between 1 and 100.\nExpected input: asciitotal string integer(1-100)\n");
        exit(EXIT_FAILURE);
    }

    //check errno
    if(errno > 0){
        printf("error #:%i\n",errno);
        exit(EXIT_FAILURE);
    }

    printf("The ASCII total of the string = %i\nThe total * multiplier = \t%i\n",total, total*in_int);



    return 0;
}
    
