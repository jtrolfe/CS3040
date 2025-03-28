#include <stdio.h>

#define PI      3.1415
#define RADIUS  10.6
#define SUCCESS 0

int main(void)
{
    float area;
    float radius = RADIUS;

    area = (PI * radius * radius);

    printf("The area of a circle when radius is %.1f = %.2f.\n",
           radius, area);

    return SUCCESS;
}
