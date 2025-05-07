#include <stdio.h>
#include <stdlib.h>
#include "module2.h"
#include "module2.h"

int main(void)
{
    int x;

    x = foo();

    printf("foo returned %d\n", x);

    return EXIT_SUCCESS;
}
