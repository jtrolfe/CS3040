#include <stdio.h>
#include <stdlib.h>
#include<errno.h>

void greeting(){
    printf("Hello World\n");
}

float half(int value){
    return (float)value/2;
}

int main(void)
{
    greeting();


    char input[100];
    int inputValue;

    printf("Enter an integer:");
    scanf("%99s",input);
    errno = 0;
    inputValue = strtol(input,NULL,10);
    if(errno != 0){
        printf("Error # %i", errno);
        exit(EXIT_FAILURE);
    }
    printf("Half of %i is %.2f\n", inputValue, half(inputValue));

    return EXIT_SUCCESS;
}
