#include <stdio.h>

#define MIN(X, Y) \
    ((X < Y) ? X : Y)

int main(void) {
    int smallest = 0;
    int x = 42;
    int y = 99;

    printf("x before: %i\n", x);
    printf("y before: %i\n\n", y);

    smallest = MIN(++x,y);
    printf("Which is smaller? %i or %i?  The answer: %i\n\n", x, y, smallest);

    printf("x after: %i\n", x);
    printf("y after: %i\n", y);

    return 0;
}

