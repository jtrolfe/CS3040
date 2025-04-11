#include <stdio.h>
#include <string.h>

#define MAKE_MAX 20
#define MODEL_MAX 20
#define MAX_CARS 100
#define SUCCESS 0

enum car_type {GAS, ELECTRIC};
struct car_t {
    char make[MAKE_MAX];
    char model[MODEL_MAX];
    enum car_type kind;
    union {
        // The following structs "overlap" (use the same memory)
        // so only one at a time can be used. The "kind" variable
        // above tells you which one is currently being used.
        struct {
            unsigned int num_motors;
            unsigned int kilowatts;
            float mpkh;
        } electric;
        struct {
            float liters;
            float tanksize;
            float mpg;
        } gas;
    } details;
};


int main(void)
{
    struct car_t cars[MAX_CARS];
    unsigned int num_cars = 0;

    // Set the details for a gas vehicle
    strcpy(cars[0].make, "Dodge");
    strcpy(cars[0].model,"RAM");
    cars[0].kind = GAS;
    cars[0].details.gas.liters   = 6.3;
    cars[0].details.gas.tanksize = 20;
    cars[0].details.gas.mpg      = 12.2;
    ++num_cars;

    // Set the details for an electric vehicle
    strcpy(cars[1].make, "Tesla");
    strcpy(cars[1].model,"Model S");
    cars[1].kind = ELECTRIC;
    cars[1].details.electric.num_motors = 2;
    cars[1].details.electric.kilowatts  = 90;
    cars[1].details.electric.mpkh       = 3.1;
    ++num_cars;

    // Print out the data
    for (int i=0; i < num_cars; ++i) {
        printf("%s %s:\n", cars[i].make, cars[i].model);

        if (cars[i].kind == GAS) {
            // Refer to the GAS part of the union
            printf("\tInternal Cumbustion Engine\n");
            printf("\tEngine size: %2.1f\n",
                   cars[i].details.gas.liters);
            printf("\tTank size: %2.2f\n",
                   cars[i].details.gas.tanksize);
            printf("\tMPG: %2.2f\n",
                   cars[i].details.gas.mpg);
        } else if (cars[i].kind == ELECTRIC) {
            // Refer to the Electric part of the union
            printf("\tElectric\n");
            printf("\tNumber of motors: %i\n", 
                   cars[i].details.electric.num_motors);
            printf("\tBattery (kW): %i\n",
                   cars[i].details.electric.kilowatts);
            printf("\tMPKwh: %3.1f\n",
                   cars[i].details.electric.mpkh);
        } else {
            printf("CORRUPTED DATA on row %i\n", i);
        }
    }

    return SUCCESS;
}
