#include <stdio.h>

#define SUCCESS 0

int main(void)
{
    int x = 6;

    switch (x) {
        case 1:
            printf("x = 1\n");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            printf("(x > 1) and (x < 6)\n");
            break;
        case 10:
            printf("x = 10\n");
            break;
        default:
            printf("x is a mess\n");
            break;
    }

    return SUCCESS;
}
