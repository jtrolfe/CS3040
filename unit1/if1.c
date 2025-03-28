// This is the wrong way
#include <stdio.h>

#define SUCCESS 0

int main()
{
    if (1 < 2)
        printf("1\n");
    else
        printf("2\n");
        printf("3\n");

    return SUCCESS;
}
