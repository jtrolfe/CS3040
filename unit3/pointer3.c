#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int x = 336;
    unsigned int *pint = &x;

    printf("*pint when accessed as an int = %u\n", *pint);
    printf("*pint when accessed as a char = %c\n", *((char *) pint));
    printf("*pint when accessed as a char = %c\n", (char) *pint);

    return EXIT_SUCCESS;
}

