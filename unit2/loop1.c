#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int i = 0;

    while (i < 10) {
        printf("i = %d\n", i);
        ++i;
    }

    return SUCCESS;
}
