#include <stdio.h>

#define SUCCESS 0

int main(void)
{
/* Trying to wrap a comment around a prior comment does not work
    /* Old style comment
       continues until it
       sees a matching --> */
*/
    printf("my number is %d\n", 42);

    return SUCCESS;
}
