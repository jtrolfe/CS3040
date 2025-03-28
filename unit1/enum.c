#include <stdio.h>

int main()
{
    enum days {MON, TUE, WED, THU, FRI, SAT, SUN};

    enum days day;    //Note: day is a variable
                      // of type, enum days

    day = MON;
    printf("Workday starts on %d.\n", day);

    day = day + 1;
    printf("And then comes %d.\n", day);

    day = 42;

    return 0;
}
