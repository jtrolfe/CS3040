#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int i = 0;

    do {
        printf("i = %d\n", i);
        ++i;
    } while (i < 10);

    return SUCCESS;
}
