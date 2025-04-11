#include <stdio.h>
#include <string.h>

#define MAX_NAME 22
#define SUCCESS  0

struct city {
    char  name[MAX_NAME];
    float longitude;
    float latitude;
};

int main(void)
{
    struct city stockholm;
    //struct city interlaken;

    stockholm.longitude = 59.329323;
    stockholm.latitude  = 18.068581;
    strncpy(stockholm.name, "Stockholm", MAX_NAME-1);

    printf("Longitude of %s is %f.\n",
           stockholm.name, stockholm.longitude);

    return SUCCESS;
}
