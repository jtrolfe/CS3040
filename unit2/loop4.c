#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int i;

    for (i=0; i < 10; ++i) {
        if (i == 5) {
            continue;
        }
        printf("i = %d\n", i);
    }

    return SUCCESS;
}
