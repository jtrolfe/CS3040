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

#define BASE 10
#define NUM_ARGS 2

int main(int argc, char *argv[]){
    //Local varialbles

    //Verify correct number of arguments
    if(argc != NUM_ARGS){
        printf("Expected two arguments");
        exit(EXIT_FAILURE);
    }
}
    
