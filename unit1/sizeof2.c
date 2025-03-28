#include <stdio.h>

int main(void)
{
    int char_size    = sizeof(char);
    int short_size   = sizeof(short);
    int int_size     = sizeof(int);
    int long_size    = sizeof(long);
    int llong_size   = sizeof(long long);
    int float_size   = sizeof(float);
    int double_size  = sizeof(double);
    int ldouble_size = sizeof(long double);

    printf("bytes used by char          = %i\n", char_size);
    printf("bytes used by short int     = %i\n", short_size);
    printf("bytes used by int           = %i\n", int_size);
    printf("bytes used by long int      = %i\n", long_size);
    printf("bytes used by long long int = %i\n", llong_size);
    printf("--------------------------------\n");
    printf("bytes used by float         = %i\n", float_size);
    printf("bytes used by double        = %i\n", double_size);
    printf("bytes used by long double   = %i\n", ldouble_size);

    return 0;
}
