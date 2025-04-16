#include <stdio.h>
#include <stdlib.h>

int inc(int number)
{
    number = number + 1;
    return number;
}

int main(void)
{
    int x = 42;

    printf("x starts out as %d\n", x);

    printf("The number after %d is %d\n", x, inc(x));
    printf("x is still %d\n", x);

    x = inc(x);
    printf("x is now %d\n", x);

    return EXIT_SUCCESS;
}



