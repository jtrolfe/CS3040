#include <stdio.h>

#define SUCCESS 0

int main()
{
    int x = 4;
    int y = 0;
    printf("x = %i, y = %i\n", x, y);

    // What is this conditional accomplishing?
    if ((y == 0) || (x = x/y)) {
        printf("x = %i, y = %i\n", x, y);
    } else {
        printf("x = %i, y = %i\n", x, y);
    }

    return SUCCESS;
}
