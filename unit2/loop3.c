#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i) {
        printf("i = %i\n", i);
    }

    return SUCCESS;
}
