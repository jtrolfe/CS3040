#include <stdio.h>
#include <stdlib.h>

void display(char *msg)
{
    printf("%s\n", msg);
}


int main(void)
{
    void (*foo)(char*) = NULL;

    foo = &display;

    // Any difference between these?
    (*foo)("Hello World");  //deref pointer foo
    display("Hello World"); //call display directly
    foo("Hello World");     //call foo directly - fail??

    return EXIT_SUCCESS;
}
