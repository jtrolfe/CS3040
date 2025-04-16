#include <stdio.h>
#include <stdlib.h>

void inc(int *number)
{
    *number = *number + 1;
}


int main(void)
{
    int x = 42;
    printf("x starts out as %d\n", x);

    inc(&x);
    printf("x is now %d\n", x);

    return EXIT_SUCCESS;
}
