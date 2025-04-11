#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int i = 0;

again:
    printf("i = %d\n", i);
    ++i;
    if (i < 10) {
        goto again;
    }

    return SUCCESS;
}
