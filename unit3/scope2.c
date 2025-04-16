#include <stdio.h>
#include <stdlib.h>

int main(void)
{                                  // <--------------+
    int i = 42;                    //                |
    printf("i = %d\n", i);         //                |
    {                              // <-----------+  |
        int i = 86;                //             |  |
        printf("i = %d\n", i);     //             |  |
        {                          // <--------+  |  |
            int i = 99;            //          |  |  |
            printf("i = %d\n", i); //          |  |  |
        }                          // <--------+  |  |
        printf("i = %d\n", i);     //             |  |
    }                              // <-----------+  |
    printf("i = %d\n", i);         //                |
                                   //                |
    return EXIT_SUCCESS;           //                |
}                                  // <--------------+
