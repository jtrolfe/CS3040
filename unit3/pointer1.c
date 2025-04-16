#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 3;
    int y = 5;
    int z;
    int *px = NULL;
    int *py = NULL;

    px = &x;
    py = &y;

    z = *px * *py;               // counting on precedence
    printf("%d x %d = %d\n", x, y, z);

    z = (*px) * (*py);           // explicit order
    printf("%d x %d = %d\n", x, y, z);

    return EXIT_SUCCESS;
}

