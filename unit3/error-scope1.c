#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 42;

    printf("%d\n", i);
    {
        int j = ++i;
        printf("%d\n%d\n", i, j);
    }
    printf("%d\n%d\n", i, j);
    return EXIT_SUCCESS;
}
