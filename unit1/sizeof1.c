#include <stdio.h>

int main(void)
{
    int char_size = sizeof(char);
    int int_size  = sizeof(int);

    printf("bytes used by char = %i\n", char_size);
    printf("bytes used by int  = %i\n", int_size);

    return 0;
}
