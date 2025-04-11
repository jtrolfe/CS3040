#include <stdio.h>

int calcArea(int h,int w){
    return h*w;
}
int main()
{
    int width   = 42;
    int height  = 99;
    int area = calcArea(height,width);

    area = width*height;

    printf("A rectangle of dimension %ix%i has an area of %i\n",width,height,area);
    return 0;
}
