#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;

    printf("'x' is located at address    %p\n", &x);
    printf("'main' is located at address %p\n", &main);

    return EXIT_SUCCESS;
}
