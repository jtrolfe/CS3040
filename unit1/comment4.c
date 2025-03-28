#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    // Below are three methods for "commenting out"
    // multiple lines of code in a program, such as
    // when debugging.

    /*
    printf("my number is %d\n", 37);
    printf("my number is %d\n", 38);
    printf("my number is %d\n", 39);
    printf("my number is %d\n", 40);
    printf("my number is %d\n", 41); */
    printf("my number is %d\n", 42);

    //printf("my number is %d\n", 37);
    //printf("my number is %d\n", 38);
    //printf("my number is %d\n", 39);
    //printf("my number is %d\n", 40);
    //printf("my number is %d\n", 41);
    printf("my number is %d\n", 42);

#if 0
    printf("my number is %d\n", 37);
    printf("my number is %d\n", 38);
    printf("my number is %d\n", 39);
    printf("my number is %d\n", 40);
    printf("my number is %d\n", 41);
#endif
    printf("my number is %d\n", 42);
    return SUCCESS;
}
