#include <stdio.h>

int main()
{
    int *my_pointer = NULL;
    printf("%i\n",*my_pointer);
    int my_number = 42;
    my_pointer = &my_number;


    *my_pointer = 99;

    printf("%i\n",*my_pointer);

    return 0;
}
