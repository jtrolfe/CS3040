#include <stdio.h>
#include <stdlib.h>

void greeting(){
    printf("Hello World\n");
}

float half(int value){
    return (float)value/2;
}

int main(void)
{
    greeting();


    char input[10];
    int inputValue;

    printf("Enter an integer:");
    scanf("%9s",input);
    inputValue = strtol(input,NULL,10);
    printf("Half of %i is %.2f\n", inputValue, half(inputValue));

    return EXIT_SUCCESS;
}
