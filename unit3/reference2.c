#include <stdio.h>
#include <stdlib.h>

void inc(int *number);

int main(void)
{
    int x = 42;
    printf("The number after %d is ", x);

    inc(&x);
    printf("%d\n", x);

    return EXIT_SUCCESS;
}


void inc(int *number)
{
    *number = *number + 1;
}
