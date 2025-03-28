// This is an example of something that doesn't work as expected
#include <stdio.h>

#define SUCCESS 0

int main()
{
    int x = 42;
    int y = 43;

    printf("x = %d, y = %d\n", x, y);

    if (x = y) { // <-- This is wrong
        printf("x = %d, y = %d\n", x, y);
    }

    return SUCCESS;
}
