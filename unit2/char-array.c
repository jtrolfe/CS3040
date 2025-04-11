#include <stdio.h>

int main()
{
    char char1[5] = {'a', 'b', 'c', 'd', 'e'};
    char char2[5] = "abcde";

//    char2 = char1;

    if (char1 == char2) {
        printf("arrays are the same\n");
    } else {
        printf("arrays not the same\n");
    }

    return 0;
}
