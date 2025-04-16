#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int side1 = 4;
    int side2 = 8;
    int area  = side1 * side2;

    printf("----------------------------------\n");
    printf("Name  | Value | Location\n");
    printf("----------------------------------\n");
    printf("side1 | %5d | %p\n", side1, &side1);
    printf("side2 | %5d | %p\n", side2, &side2);
    printf("area  | %5d | %p\n", area,  &area);

    return EXIT_SUCCESS;
}

