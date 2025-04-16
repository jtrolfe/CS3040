#include <stdio.h>
#include <stdlib.h>

int main()
{
    char foo[10];
    char *p = NULL;

    foo[2] = 'R';

    p = foo;
    // p = &foo;      // same result - not necssary
    // p = (&foo[0]); // same result - not necssary

    printf("foo[2] = %c\n", *(p+2));
    printf("foo[2] = %c\n", p[2]);
    printf("foo[2] = %c\n", foo[2]);

    return EXIT_SUCCESS;
}
