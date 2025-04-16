#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *pchar = NULL;
    int  *pint  = NULL;

    printf("sizeof char pointer = %lu\n", sizeof(pchar));
    printf("sizeof int pointer  = %lu\n", sizeof(pint));

    return EXIT_SUCCESS;
}

