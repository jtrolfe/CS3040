#include <stdio.h>
#include <string.h>  // NOTICE this include

#define SHORTMAX 10
#define FULLMAX  25

int main()
{
    char last [SHORTMAX] = "Doe";
    char first[SHORTMAX] = "01234567890123456";
    char full [FULLMAX];

    strcat(full,first);
    strcat(full, " ");
    strcat(full, last);
    strcat(full, "\n");

    printf("%s",full);

    return 0;
}
