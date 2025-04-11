#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//#define BASE_10 10
#define BASE_10 37

int main(void)
{
    char str[] = "42";
    //char str[] = "99999999999999999999";
    long num;

    // Here is the typical way errno is used...
    // Initialize errno value to 0
    errno = 0;
    // Call a function that sets errno, e.g., strtol
    num = strtol(str, NULL, BASE_10);
    // Check errno value to see if error occured in the function
    if (errno != 0) {
        // An error occured, so do something to respond to it
        printf("The string could not be converted to a long. %i\n",errno);
        exit(EXIT_FAILURE);
    }

    printf("The converted number is %li.\n", num);

    return EXIT_SUCCESS;
}
